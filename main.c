#include "bms_fsm.h"
#include "bootstrap.h"
#include "bms_scheduler.h"

BMS_Scheduler_Init();
Bootstrap_Init();
BMS_FSM_Init();

while(1)
{
  BMS_Scheduler_Run();
}
