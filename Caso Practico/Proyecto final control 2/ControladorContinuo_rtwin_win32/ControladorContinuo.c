/*
 * ControladorContinuo.c
 *
 * Code generation for model "ControladorContinuo".
 *
 * Model version              : 1.22
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Fri May 23 09:48:52 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ControladorContinuo.h"
#include "ControladorContinuo_private.h"
#include "ControladorContinuo_dt.h"

/* options for Real-Time Windows Target board 0 */
static double RTWinBoardOptions0[] = {
  1.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
BlockIO_ControladorContinuo ControladorContinuo_B;

/* Continuous states */
ContinuousStates_ControladorContinuo ControladorContinuo_X;

/* Block states (auto storage) */
D_Work_ControladorContinuo ControladorContinuo_DWork;

/* Real-time model */
RT_MODEL_ControladorContinuo ControladorContinuo_M_;
RT_MODEL_ControladorContinuo *const ControladorContinuo_M =
  &ControladorContinuo_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ControladorContinuo_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  ControladorContinuo_output();
  ControladorContinuo_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  ControladorContinuo_output();
  ControladorContinuo_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  ControladorContinuo_output();
  ControladorContinuo_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  ControladorContinuo_output();
  ControladorContinuo_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  ControladorContinuo_output();
  ControladorContinuo_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void ControladorContinuo_output(void)
{
  real_T currentTime;
  int32_T i;
  real_T rtb_Integrator3_idx;
  real_T rtb_Integrator3_idx_0;
  real_T rtb_Integrator3_idx_1;
  if (rtmIsMajorTimeStep(ControladorContinuo_M)) {
    /* set solver stop time */
    if (!(ControladorContinuo_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ControladorContinuo_M->solverInfo,
                            ((ControladorContinuo_M->Timing.clockTickH0 + 1) *
        ControladorContinuo_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ControladorContinuo_M->solverInfo,
                            ((ControladorContinuo_M->Timing.clockTick0 + 1) *
        ControladorContinuo_M->Timing.stepSize0 +
        ControladorContinuo_M->Timing.clockTickH0 *
        ControladorContinuo_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ControladorContinuo_M)) {
    ControladorContinuo_M->Timing.t[0] = rtsiGetT
      (&ControladorContinuo_M->solverInfo);
  }

  /* Integrator: '<Root>/Integrator3' */
  rtb_Integrator3_idx = ControladorContinuo_X.Integrator3_CSTATE[0];
  rtb_Integrator3_idx_0 = ControladorContinuo_X.Integrator3_CSTATE[1];
  rtb_Integrator3_idx_1 = ControladorContinuo_X.Integrator3_CSTATE[2];

  /* Sum: '<Root>/Sum9' incorporates:
   *  Gain: '<Root>/-ki'
   *  Gain: '<Root>/-kp'
   *  Integrator: '<Root>/Integrator3'
   *  Integrator: '<Root>/Integrator4'
   */
  ControladorContinuo_B.Sum9 = ((ControladorContinuo_P.kp_Gain[0] *
    ControladorContinuo_X.Integrator3_CSTATE[0] + ControladorContinuo_P.kp_Gain
    [1] * ControladorContinuo_X.Integrator3_CSTATE[1]) +
    ControladorContinuo_P.kp_Gain[2] * ControladorContinuo_X.Integrator3_CSTATE
    [2]) + ControladorContinuo_P.ki_Gain *
    ControladorContinuo_X.Integrator4_CSTATE;
  if (rtmIsMajorTimeStep(ControladorContinuo_M)) {
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) ControladorContinuo_P.AnalogOutput_RangeMode;
        parm.rangeidx = ControladorContinuo_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &ControladorContinuo_P.AnalogOutput_Channels,
                       &ControladorContinuo_B.Sum9, &parm);
      }
    }

    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) ControladorContinuo_P.AnalogInput_RangeMode;
      parm.rangeidx = ControladorContinuo_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &ControladorContinuo_P.AnalogInput_Channels,
                     &ControladorContinuo_B.AnalogInput, &parm);
    }
  }

  /* Step: '<Root>/Step' */
  currentTime = ControladorContinuo_M->Timing.t[0];
  if (currentTime < ControladorContinuo_P.Step_Time) {
    currentTime = ControladorContinuo_P.Step_Y0;
  } else {
    currentTime = ControladorContinuo_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Gain: '<S1>/Slider Gain' */
  ControladorContinuo_B.SliderGain = ControladorContinuo_P.SliderGain_Gain *
    currentTime;
  if (rtmIsMajorTimeStep(ControladorContinuo_M)) {
  }

  /* Sum: '<Root>/Sum10' */
  ControladorContinuo_B.Sum10 = ControladorContinuo_B.SliderGain -
    ControladorContinuo_B.AnalogInput;
  if (rtmIsMajorTimeStep(ControladorContinuo_M)) {
    /* Gain: '<Root>/h' */
    ControladorContinuo_B.h[0] = ControladorContinuo_P.h_Gain[0] *
      ControladorContinuo_B.AnalogInput;
    ControladorContinuo_B.h[1] = ControladorContinuo_P.h_Gain[1] *
      ControladorContinuo_B.AnalogInput;
    ControladorContinuo_B.h[2] = ControladorContinuo_P.h_Gain[2] *
      ControladorContinuo_B.AnalogInput;
  }

  /* Sum: '<Root>/Sum8' incorporates:
   *  Gain: '<Root>/a-hc'
   *  Gain: '<Root>/b2'
   */
  for (i = 0; i < 3; i++) {
    ControladorContinuo_B.Sum8[i] = ((ControladorContinuo_P.ahc_Gain[i + 3] *
      rtb_Integrator3_idx_0 + ControladorContinuo_P.ahc_Gain[i] *
      rtb_Integrator3_idx) + ControladorContinuo_P.ahc_Gain[i + 6] *
      rtb_Integrator3_idx_1) + (ControladorContinuo_P.b2_Gain[i] *
      ControladorContinuo_B.Sum9 + ControladorContinuo_B.h[i]);
  }

  /* End of Sum: '<Root>/Sum8' */
}

/* Model update function */
void ControladorContinuo_update(void)
{
  if (rtmIsMajorTimeStep(ControladorContinuo_M)) {
    rt_ertODEUpdateContinuousStates(&ControladorContinuo_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ControladorContinuo_M->Timing.clockTick0)) {
    ++ControladorContinuo_M->Timing.clockTickH0;
  }

  ControladorContinuo_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ControladorContinuo_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ControladorContinuo_M->Timing.clockTick1)) {
      ++ControladorContinuo_M->Timing.clockTickH1;
    }

    ControladorContinuo_M->Timing.t[1] =
      ControladorContinuo_M->Timing.clockTick1 *
      ControladorContinuo_M->Timing.stepSize1 +
      ControladorContinuo_M->Timing.clockTickH1 *
      ControladorContinuo_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ControladorContinuo_derivatives(void)
{
  StateDerivatives_ControladorContinuo *_rtXdot;
  _rtXdot = ((StateDerivatives_ControladorContinuo *)
             ControladorContinuo_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = ControladorContinuo_B.Sum10;

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ControladorContinuo_B.Sum8[0];
  _rtXdot->Integrator3_CSTATE[1] = ControladorContinuo_B.Sum8[1];
  _rtXdot->Integrator3_CSTATE[2] = ControladorContinuo_B.Sum8[2];
}

/* Model initialize function */
void ControladorContinuo_initialize(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) ControladorContinuo_P.AnalogOutput_RangeMode;
      parm.rangeidx = ControladorContinuo_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &ControladorContinuo_P.AnalogOutput_Channels,
                     &ControladorContinuo_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator4' */
  ControladorContinuo_X.Integrator4_CSTATE =
    ControladorContinuo_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  ControladorContinuo_X.Integrator3_CSTATE[0] =
    ControladorContinuo_P.Integrator3_IC;
  ControladorContinuo_X.Integrator3_CSTATE[1] =
    ControladorContinuo_P.Integrator3_IC;
  ControladorContinuo_X.Integrator3_CSTATE[2] =
    ControladorContinuo_P.Integrator3_IC;
}

/* Model terminate function */
void ControladorContinuo_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) ControladorContinuo_P.AnalogOutput_RangeMode;
      parm.rangeidx = ControladorContinuo_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &ControladorContinuo_P.AnalogOutput_Channels,
                     &ControladorContinuo_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ControladorContinuo_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ControladorContinuo_update();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ControladorContinuo_initialize();
}

void MdlTerminate(void)
{
  ControladorContinuo_terminate();
}

RT_MODEL_ControladorContinuo *ControladorContinuo(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ControladorContinuo_M, 0,
                sizeof(RT_MODEL_ControladorContinuo));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControladorContinuo_M->solverInfo,
                          &ControladorContinuo_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControladorContinuo_M->solverInfo, &rtmGetTPtr
                (ControladorContinuo_M));
    rtsiSetStepSizePtr(&ControladorContinuo_M->solverInfo,
                       &ControladorContinuo_M->Timing.stepSize0);
    rtsiSetdXPtr(&ControladorContinuo_M->solverInfo,
                 &ControladorContinuo_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ControladorContinuo_M->solverInfo,
                         &ControladorContinuo_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ControladorContinuo_M->solverInfo,
      &ControladorContinuo_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ControladorContinuo_M->solverInfo,
                          (&rtmGetErrorStatus(ControladorContinuo_M)));
    rtsiSetRTModelPtr(&ControladorContinuo_M->solverInfo, ControladorContinuo_M);
  }

  rtsiSetSimTimeStep(&ControladorContinuo_M->solverInfo, MAJOR_TIME_STEP);
  ControladorContinuo_M->ModelData.intgData.y =
    ControladorContinuo_M->ModelData.odeY;
  ControladorContinuo_M->ModelData.intgData.f[0] =
    ControladorContinuo_M->ModelData.odeF[0];
  ControladorContinuo_M->ModelData.intgData.f[1] =
    ControladorContinuo_M->ModelData.odeF[1];
  ControladorContinuo_M->ModelData.intgData.f[2] =
    ControladorContinuo_M->ModelData.odeF[2];
  ControladorContinuo_M->ModelData.intgData.f[3] =
    ControladorContinuo_M->ModelData.odeF[3];
  ControladorContinuo_M->ModelData.intgData.f[4] =
    ControladorContinuo_M->ModelData.odeF[4];
  ControladorContinuo_M->ModelData.intgData.f[5] =
    ControladorContinuo_M->ModelData.odeF[5];
  ControladorContinuo_M->ModelData.contStates = ((real_T *)
    &ControladorContinuo_X);
  rtsiSetSolverData(&ControladorContinuo_M->solverInfo, (void *)
                    &ControladorContinuo_M->ModelData.intgData);
  rtsiSetSolverName(&ControladorContinuo_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ControladorContinuo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ControladorContinuo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ControladorContinuo_M->Timing.sampleTimes =
      (&ControladorContinuo_M->Timing.sampleTimesArray[0]);
    ControladorContinuo_M->Timing.offsetTimes =
      (&ControladorContinuo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ControladorContinuo_M->Timing.sampleTimes[0] = (0.0);
    ControladorContinuo_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ControladorContinuo_M->Timing.offsetTimes[0] = (0.0);
    ControladorContinuo_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ControladorContinuo_M, &ControladorContinuo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ControladorContinuo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ControladorContinuo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ControladorContinuo_M, -1);
  ControladorContinuo_M->Timing.stepSize0 = 0.01;
  ControladorContinuo_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  ControladorContinuo_M->Sizes.checksums[0] = (2033287125U);
  ControladorContinuo_M->Sizes.checksums[1] = (75493170U);
  ControladorContinuo_M->Sizes.checksums[2] = (499546016U);
  ControladorContinuo_M->Sizes.checksums[3] = (1940763404U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ControladorContinuo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ControladorContinuo_M->extModeInfo,
      &ControladorContinuo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ControladorContinuo_M->extModeInfo,
                        ControladorContinuo_M->Sizes.checksums);
    rteiSetTPtr(ControladorContinuo_M->extModeInfo, rtmGetTPtr
                (ControladorContinuo_M));
  }

  ControladorContinuo_M->solverInfoPtr = (&ControladorContinuo_M->solverInfo);
  ControladorContinuo_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ControladorContinuo_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ControladorContinuo_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ControladorContinuo_M->ModelData.blockIO = ((void *) &ControladorContinuo_B);
  (void) memset(((void *) &ControladorContinuo_B), 0,
                sizeof(BlockIO_ControladorContinuo));

  /* parameters */
  ControladorContinuo_M->ModelData.defaultParam = ((real_T *)
    &ControladorContinuo_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ControladorContinuo_X;
    ControladorContinuo_M->ModelData.contStates = (x);
    (void) memset((void *)&ControladorContinuo_X, 0,
                  sizeof(ContinuousStates_ControladorContinuo));
  }

  /* states (dwork) */
  ControladorContinuo_M->Work.dwork = ((void *) &ControladorContinuo_DWork);
  (void) memset((void *)&ControladorContinuo_DWork, 0,
                sizeof(D_Work_ControladorContinuo));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ControladorContinuo_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  ControladorContinuo_M->Sizes.numContStates = (4);/* Number of continuous states */
  ControladorContinuo_M->Sizes.numY = (0);/* Number of model outputs */
  ControladorContinuo_M->Sizes.numU = (0);/* Number of model inputs */
  ControladorContinuo_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ControladorContinuo_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ControladorContinuo_M->Sizes.numBlocks = (16);/* Number of blocks */
  ControladorContinuo_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  ControladorContinuo_M->Sizes.numBlockPrms = (33);/* Sum of parameter "widths" */
  return ControladorContinuo_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
