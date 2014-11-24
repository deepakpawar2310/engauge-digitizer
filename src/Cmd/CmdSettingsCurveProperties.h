#ifndef CMD_SETTINGS_CURVE_PROPERTIES_H
#define CMD_SETTINGS_CURVE_PROPERTIES_H

#include "CmdAbstract.h"
#include "DlgModelCurveProperties.h"
#include "LineStyle.h"
#include "PointStyle.h"

class DlgModelCurveProperties;

/// Command for DlgSettingsCurveProperties
class CmdSettingsCurveProperties : public CmdAbstract
{
public:
  /// Single constructor.
  CmdSettingsCurveProperties(MainWindow &mainWindow,
                             Document &document,
                             const DlgModelCurveProperties &modelCurvePropertiesBefore,
                             const DlgModelCurveProperties &modelCurvePropertiesAfter);

  virtual void cmdRedo ();
  virtual void cmdUndo ();

private:
  CmdSettingsCurveProperties();

  DlgModelCurveProperties m_modelCurvePropertiesBefore;
  DlgModelCurveProperties m_modelCurvePropertiesAfter;
};

#endif // CMD_SETTINGS_CURVE_PROPERTIES_H
