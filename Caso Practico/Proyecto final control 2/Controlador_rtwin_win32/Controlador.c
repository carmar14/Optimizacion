/*
 * Controlador.c
 *
 * Code generation for model "Controlador".
 *
 * Model version              : 1.21
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Fri May 23 09:51:53 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Controlador.h"
#include "Controlador_private.h"
#include "Controlador_dt.h"

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
BlockIO_Controlador Controlador_B;

/* Block states (auto storage) */
D_Work_Controlador Controlador_DWork;

/* Real-time model */
RT_MODEL_Controlador Controlador_M_;
RT_MODEL_Controlador *const Controlador_M = &Controlador_M_;

/* Model output function */
void Controlador_output(void)
{
  int32_T i;
  real_T rtb_UnitDelay1_idx;
  real_T rtb_UnitDelay1_idx_0;
  real_T rtb_UnitDelay1_idx_1;

  /* Step: '<Root>/Step' */
  if (Controlador_M->Timing.t[0] < Controlador_P.Step_Time) {
    rtb_UnitDelay1_idx = Controlador_P.Step_Y0;
  } else {
    rtb_UnitDelay1_idx = Controlador_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Gain: '<S1>/Slider Gain' */
  Controlador_B.SliderGain = Controlador_P.SliderGain_Gain * rtb_UnitDelay1_idx;

  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) Controlador_P.AnalogInput_RangeMode;
    parm.rangeidx = Controlador_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &Controlador_P.AnalogInput_Channels,
                   &Controlador_B.AnalogInput, &parm);
  }

  /* DiscreteTransferFcn: '<Root>/integrador' incorporates:
   *  Sum: '<Root>/Sum10'
   */
  Controlador_DWork.integrador_tmp = ((Controlador_B.SliderGain -
    Controlador_B.AnalogInput) - Controlador_P.integrador_DenCoef[1] *
    Controlador_DWork.integrador_DSTATE) / Controlador_P.integrador_DenCoef[0];

  /* UnitDelay: '<Root>/Unit Delay1' */
  rtb_UnitDelay1_idx = Controlador_DWork.UnitDelay1_DSTATE[0];
  rtb_UnitDelay1_idx_0 = Controlador_DWork.UnitDelay1_DSTATE[1];
  rtb_UnitDelay1_idx_1 = Controlador_DWork.UnitDelay1_DSTATE[2];

  /* Sum: '<Root>/Sum9' incorporates:
   *  DiscreteTransferFcn: '<Root>/integrador'
   *  Gain: '<Root>/-kidis'
   *  Gain: '<Root>/-kpdis'
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  Controlador_B.Sum9 = (Controlador_P.integrador_NumCoef[0] *
                        Controlador_DWork.integrador_tmp +
                        Controlador_P.integrador_NumCoef[1] *
                        Controlador_DWork.integrador_DSTATE) *
    Controlador_P.kidis_Gain + ((Controlador_P.kpdis_Gain[0] *
    Controlador_DWork.UnitDelay1_DSTATE[0] + Controlador_P.kpdis_Gain[1] *
    Controlador_DWork.UnitDelay1_DSTATE[1]) + Controlador_P.kpdis_Gain[2] *
    Controlador_DWork.UnitDelay1_DSTATE[2]);

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Controlador_P.AnalogOutput_RangeMode;
      parm.rangeidx = Controlador_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Controlador_P.AnalogOutput_Channels, &Controlador_B.Sum9,
                     &parm);
    }
  }

  /* Sum: '<Root>/Sum8' incorporates:
   *  Gain: '<Root>/adis-hdiscdis'
   *  Gain: '<Root>/bdis2'
   *  Gain: '<Root>/hdis'
   */
  for (i = 0; i < 3; i++) {
    Controlador_B.Sum8[i] = ((Controlador_P.adishdiscdis_Gain[i + 3] *
      rtb_UnitDelay1_idx_0 + Controlador_P.adishdiscdis_Gain[i] *
      rtb_UnitDelay1_idx) + Controlador_P.adishdiscdis_Gain[i + 6] *
      rtb_UnitDelay1_idx_1) + (Controlador_P.hdis_Gain[i] *
      Controlador_B.AnalogInput + Controlador_P.bdis2_Gain[i] *
      Controlador_B.Sum9);
  }

  /* End of Sum: '<Root>/Sum8' */
}

/* Model update function */
void Controlador_update(void)
{
  /* Update for DiscreteTransferFcn: '<Root>/integrador' */
  Controlador_DWork.integrador_DSTATE = Controlador_DWork.integrador_tmp;

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  Controlador_DWork.UnitDelay1_DSTATE[0] = Controlador_B.Sum8[0];
  Controlador_DWork.UnitDelay1_DSTATE[1] = Controlador_B.Sum8[1];
  Controlador_DWork.UnitDelay1_DSTATE[2] = Controlador_B.Sum8[2];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Controlador_M->Timing.clockTick0)) {
    ++Controlador_M->Timing.clockTickH0;
  }

  Controlador_M->Timing.t[0] = Controlador_M->Timing.clockTick0 *
    Controlador_M->Timing.stepSize0 + Controlador_M->Timing.clockTickH0 *
    Controlador_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Controlador_initialize(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Controlador_P.AnalogOutput_RangeMode;
      parm.rangeidx = Controlador_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Controlador_P.AnalogOutput_Channels,
                     &Controlador_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/integrador' */
  Controlador_DWork.integrador_DSTATE = Controlador_P.integrador_InitialStates;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  Controlador_DWork.UnitDelay1_DSTATE[0] = Controlador_P.UnitDelay1_X0;
  Controlador_DWork.UnitDelay1_DSTATE[1] = Controlador_P.UnitDelay1_X0;
  Controlador_DWork.UnitDelay1_DSTATE[2] = Controlador_P.UnitDelay1_X0;
}

/* Model terminate function */
void Controlador_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Controlador_P.AnalogOutput_RangeMode;
      parm.rangeidx = Controlador_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Controlador_P.AnalogOutput_Channels,
                     &Controlador_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Controlador_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Controlador_update();

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
  Controlador_initialize();
}

void MdlTerminate(void)
{
  Controlador_terminate();
}

RT_MODEL_Controlador *Controlador(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Controlador_M, 0,
                sizeof(RT_MODEL_Controlador));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Controlador_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Controlador_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Controlador_M->Timing.sampleTimes = (&Controlador_M->
      Timing.sampleTimesArray[0]);
    Controlador_M->Timing.offsetTimes = (&Controlador_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    Controlador_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    Controlador_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Controlador_M, &Controlador_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Controlador_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Controlador_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Controlador_M, -1);
  Controlador_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Controlador_M->Sizes.checksums[0] = (2939564045U);
  Controlador_M->Sizes.checksums[1] = (4142801335U);
  Controlador_M->Sizes.checksums[2] = (587279350U);
  Controlador_M->Sizes.checksums[3] = (4218291208U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Controlador_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Controlador_M->extModeInfo,
      &Controlador_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Controlador_M->extModeInfo,
                        Controlador_M->Sizes.checksums);
    rteiSetTPtr(Controlador_M->extModeInfo, rtmGetTPtr(Controlador_M));
  }

  Controlador_M->solverInfoPtr = (&Controlador_M->solverInfo);
  Controlador_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Controlador_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Controlador_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Controlador_M->ModelData.blockIO = ((void *) &Controlador_B);
  (void) memset(((void *) &Controlador_B), 0,
                sizeof(BlockIO_Controlador));

  /* parameters */
  Controlador_M->ModelData.defaultParam = ((real_T *)&Controlador_P);

  /* states (dwork) */
  Controlador_M->Work.dwork = ((void *) &Controlador_DWork);
  (void) memset((void *)&Controlador_DWork, 0,
                sizeof(D_Work_Controlador));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Controlador_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  Controlador_M->Sizes.numContStates = (0);/* Number of continuous states */
  Controlador_M->Sizes.numY = (0);     /* Number of model outputs */
  Controlador_M->Sizes.numU = (0);     /* Number of model inputs */
  Controlador_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Controlador_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Controlador_M->Sizes.numBlocks = (16);/* Number of blocks */
  Controlador_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  Controlador_M->Sizes.numBlockPrms = (37);/* Sum of parameter "widths" */
  return Controlador_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
