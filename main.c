#include "bms_fsm.h"
#include "bootstrap.h"
#include "bms_scheduler.h"

Bootstrap_Init();
BMS_FSM_Init();

while(1)
{
  BMS_Scheduler_Run();
}
