/******************************************************************************************************
 * (C) 2019 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef GUIDELINE_STATE_HANDLE_X_H
#define GUIDELINE_STATE_HANDLE_X_H

#include "GuidelineStateHandleAbstract.h"

/// GuidelineStateHandleAbstract instantiated for coordinate X guideline
class GuidelineStateHandleX : public GuidelineStateHandleAbstract
{
public:
  /// Single constructor.
  GuidelineStateHandleX(GuidelineStateContext &context);
  virtual ~GuidelineStateHandleX();

  virtual void begin ();
  virtual QPointF convertGraphCoordinateToScreenPoint (double valueGraph) const;
  virtual double convertScreenPointToGraphCoordinate (const QPointF &posScreen) const;
  virtual void end ();
  virtual void handleMouseRelease (const QPointF &posScene);
  virtual EllipseParameters pointToEllipse (const QPointF &posScreen) const;
  virtual QLineF pointToLine (const QPointF &posScreen) const;
  virtual QString stateName () const;

};

#endif // GUIDELINE_STATE_HANDLE_X_H
