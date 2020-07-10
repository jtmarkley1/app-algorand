#include "os.h"
#include "os_io_seproxyhal.h"
#include "algo_ui.h"

UX_FLOW_DEF_NOCB(
    ux_idle_flow_welcome_step,
    nn, //pnn,
    {
      //"", //&C_icon_dashboard,
      "Application",
      "is ready",
    });
UX_FLOW_DEF_NOCB(
    ux_idle_flow_version_step,
    bn,
    {
      "Version",
      APPVERSION,
    });
UX_FLOW_DEF_VALID(
    ux_idle_flow_exit_step,
    pb,
    os_sched_exit(-1),
    {
      &C_icon_dashboard_x,
      "Quit",
    });
UX_FLOW(ux_idle_flow,
  &ux_idle_flow_welcome_step,
  &ux_idle_flow_version_step,
  &ux_idle_flow_exit_step,
  FLOW_LOOP
);

UX_STEP_NOCB(ux_loading_1_step, bn, {"Loading...", "Please wait"});

const ux_flow_step_t * const ux_loading_flow [] = {
  &ux_loading_1_step,
  FLOW_END_STEP,
};

void
ui_loading()
{
  // reserve a display stack slot if none yet
  if(G_ux.stack_count == 0) {
    ux_stack_push();
  }
  ux_flow_init(0, ux_loading_flow, NULL);
}

void
ui_idle()
{
  // reserve a display stack slot if none yet
  if(G_ux.stack_count == 0) {
    ux_stack_push();
  }
  ux_flow_init(0, ux_idle_flow, NULL);
}
