/******************************************************************************************************
 * (C) 2020 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#include "CentipedePairCartesian.h"
#include "CentipedeSegmentAbstract.h"
#include "CentipedeSegmentConstantREllipse.h"
#include "CentipedeSegmentConstantTRadial.h"
#include "CentipedeSegmentConstantXLine.h"
#include "CentipedeSegmentConstantYLine.h"
#include "DocumentModelCoords.h"
#include "DocumentModelGuideline.h"
#include "GraphicsScene.h"
#include "mmsubs.h"
#include "Transformation.h"

CentipedePairCartesian::CentipedePairCartesian(GraphicsScene &scene,
                                               const Transformation &transformation,
                                               const DocumentModelGuideline &modelGuideline,
                                               const DocumentModelCoords & /* modelCoords */,
                                               const QPointF &posScreen) :
  m_modelGuideline (modelGuideline),
  m_centipedeXT (nullptr),
  m_centipedeYR (nullptr),
  m_posScreenStart (posScreen),
  m_selectedXTFinal (true),
  m_valueFinal (0)
{
  m_centipedeXT = new CentipedeSegmentConstantXLine (scene,
                                                     modelGuideline,
                                                     transformation,
                                                     posScreen);
  m_centipedeYR = new CentipedeSegmentConstantYLine (scene,
                                                     modelGuideline,
                                                     transformation,
                                                     posScreen);

  // Save starting graph position
  transformation.transformScreenToRawGraph(posScreen,
                                           m_posGraphStart);
}

CentipedePairCartesian::~CentipedePairCartesian()
{
  delete m_centipedeXT;
  delete m_centipedeYR;
}

bool CentipedePairCartesian::done (const QPointF &posScreen)
{
  QPointF delta = posScreen - m_posScreenStart;
  double distanceFromCenter = magnitude (delta);

  return (distanceFromCenter > m_modelGuideline.creationCircleRadius ());
}

void CentipedePairCartesian::move (const QPointF &posScreen)
{
  QPointF delta = posScreen - m_posScreenStart;
  double distanceFromCenter = magnitude (delta);

  if (updateFinalValues (posScreen)) {
    m_centipedeXT->updateRadius (m_modelGuideline.creationCircleRadius () + distanceFromCenter);
    m_centipedeYR->updateRadius (m_modelGuideline.creationCircleRadius () - distanceFromCenter);
  } else {
    m_centipedeXT->updateRadius (m_modelGuideline.creationCircleRadius () - distanceFromCenter);
    m_centipedeYR->updateRadius (m_modelGuideline.creationCircleRadius () + distanceFromCenter);
  }
}

bool CentipedePairCartesian::selectedXTFinal () const
{
  return m_selectedXTFinal;
}

bool CentipedePairCartesian::updateFinalValues (const QPointF &posScreen)
{
  // Update selection
  double distXT = m_centipedeXT->distanceToClosestEndpoint (posScreen);
  double distYR = m_centipedeYR->distanceToClosestEndpoint (posScreen);
  m_selectedXTFinal = (distXT < distYR);

  // Update value
  if (m_selectedXTFinal) {
    m_valueFinal = m_posGraphStart.x();
  } else {
    m_valueFinal = m_posGraphStart.y();
  }

  return m_selectedXTFinal;
}

double CentipedePairCartesian::valueFinal () const
{
  return m_valueFinal;
}
