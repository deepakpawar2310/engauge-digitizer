/******************************************************************************************************
 * (C) 2014 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef DLG_SETTINGS_AXES_CHECKER_H
#define DLG_SETTINGS_AXES_CHECKER_H

#include "DlgSettingsAbstractBase.h"

class ButtonWhatsThis;
class DocumentModelAxesChecker;
class DocumentModelCoords;
class Checker;
class QAbstractButton;
class QButtonGroup;
class QComboBox;
class QGraphicsScene;
class QGridLayout;
class QPushButton;
class QRadioButton;
class ViewPreview;

/// Dialog for editing axes checker settings.
class DlgSettingsAxesChecker : public DlgSettingsAbstractBase
{
  Q_OBJECT;

public:
  /// Single constructor.
  DlgSettingsAxesChecker(MainWindow &mainWindow);
  virtual ~DlgSettingsAxesChecker();

  virtual void createOptionalSaveDefault (QHBoxLayout *layout);
  virtual QWidget *createSubPanel ();
  virtual void load (CmdMediator &cmdMediator);
  virtual void setSmallDialogs (bool smallDialogs);

private slots:
  void slotGroupMode (QAbstractButton*);
  void slotLineColor(const QString &);
  void slotSeconds (const QString &);
  void slotWhatsThis ();

protected:
  virtual void handleOk ();

private:

  void createControls (QGridLayout *layout, int &row);
  void createPoints ();
  void createPreview (QGridLayout *layout, int &row);
  void updateControls();
  void updatePreview();

  ButtonWhatsThis *m_btnWhatsThis;
  
  QButtonGroup *m_groupMode;
  QRadioButton *m_btnNever;
  QRadioButton *m_btnNSeconds;
  QRadioButton *m_btnForever;

  QComboBox *m_cmbSeconds; // Seconds when HIGHLIGHT_MODE_N_SECONDS is applied

  QComboBox *m_cmbLineColor;

  QGraphicsScene *m_scenePreview;
  ViewPreview *m_viewPreview;
  Checker *m_checker;

  DocumentModelAxesChecker *m_modelAxesCheckerBefore;
  DocumentModelAxesChecker *m_modelAxesCheckerAfter;
  DocumentModelCoords *m_modelCoords;
};

#endif // DLG_SETTINGS_AXES_CHECKER_H
