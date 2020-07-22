/*
 * caracterizacion.c
 *
 * Code generation for model "caracterizacion".
 *
 * Model version              : 1.15
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Wed May 21 18:11:38 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "caracterizacion.h"
#include "caracterizacion_private.h"
#include "caracterizacion_dt.h"

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
BlockIO_caracterizacion caracterizacion_B;

/* Block states (auto storage) */
D_Work_caracterizacion caracterizacion_DWork;

/* Real-time model */
RT_MODEL_caracterizacion caracterizacion_M_;
RT_MODEL_caracterizacion *const caracterizacion_M = &caracterizacion_M_;

/* Model output function */
void caracterizacion_output(void)
{
  /* Gain: '<S1>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant'
   */
  caracterizacion_B.SliderGain = caracterizacion_P.SliderGain_Gain *
    caracterizacion_P.Constant_Value;

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) caracterizacion_P.AnalogOutput_RangeMode;
      parm.rangeidx = caracterizacion_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &caracterizacion_P.AnalogOutput_Channels,
                     &caracterizacion_B.SliderGain, &parm);
    }
  }

  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) caracterizacion_P.AnalogInput_RangeMode;
    parm.rangeidx = caracterizacion_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &caracterizacion_P.AnalogInput_Channels,
                   &caracterizacion_B.AnalogInput, &parm);
  }
}

/* Model update function */
void caracterizacion_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++caracterizacion_M->Timing.clockTick0)) {
    ++caracterizacion_M->Timing.clockTickH0;
  }

  caracterizacion_M->Timing.t[0] = caracterizacion_M->Timing.clockTick0 *
    caracterizacion_M->Timing.stepSize0 + caracterizacion_M->Timing.clockTickH0 *
    caracterizacion_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void caracterizacion_initialize(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) caracterizacion_P.AnalogOutput_RangeMode;
      parm.rangeidx = caracterizacion_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &caracterizacion_P.AnalogOutput_Channels,
                     &caracterizacion_P.AnalogOutput_InitialValue, &parm);
    }
  }
}

/* Model terminate function */
void caracterizacion_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) caracterizacion_P.AnalogOutput_RangeMode;
      parm.rangeidx = caracterizacion_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &caracterizacion_P.AnalogOutput_Channels,
                     &caracterizacion_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  caracterizacion_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  caracterizacion_update();

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
  caracterizacion_initialize();
}

void MdlTerminate(void)
{
  caracterizacion_terminate();
}

RT_MODEL_caracterizacion *caracterizacion(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)caracterizacion_M, 0,
                sizeof(RT_MODEL_caracterizacion));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = caracterizacion_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    caracterizacion_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    caracterizacion_M->Timing.sampleTimes =
      (&caracterizacion_M->Timing.sampleTimesArray[0]);
    caracterizacion_M->Timing.offsetTimes =
      (&caracterizacion_M->Timing.offsetTimesArray[0]);

    /* task periods */
    caracterizacion_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    caracterizacion_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(caracterizacion_M, &caracterizacion_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = caracterizacion_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    caracterizacion_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(caracterizacion_M, -1);
  caracterizacion_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  caracterizacion_M->Sizes.checksums[0] = (2061735249U);
  caracterizacion_M->Sizes.checksums[1] = (4124530469U);
  caracterizacion_M->Sizes.checksums[2] = (1814140338U);
  caracterizacion_M->Sizes.checksums[3] = (2352428651U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    caracterizacion_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(caracterizacion_M->extModeInfo,
      &caracterizacion_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(caracterizacion_M->extModeInfo,
                        caracterizacion_M->Sizes.checksums);
    rteiSetTPtr(caracterizacion_M->extModeInfo, rtmGetTPtr(caracterizacion_M));
  }

  caracterizacion_M->solverInfoPtr = (&caracterizacion_M->solverInfo);
  caracterizacion_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&caracterizacion_M->solverInfo, 0.01);
  rtsiSetSolverMode(&caracterizacion_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  caracterizacion_M->ModelData.blockIO = ((void *) &caracterizacion_B);
  (void) memset(((void *) &caracterizacion_B), 0,
                sizeof(BlockIO_caracterizacion));

  /* parameters */
  caracterizacion_M->ModelData.defaultParam = ((real_T *)&caracterizacion_P);

  /* states (dwork) */
  caracterizacion_M->Work.dwork = ((void *) &caracterizacion_DWork);
  (void) memset((void *)&caracterizacion_DWork, 0,
                sizeof(D_Work_caracterizacion));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    caracterizacion_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  caracterizacion_M->Sizes.numContStates = (0);/* Number of continuous states */
  caracterizacion_M->Sizes.numY = (0); /* Number of model outputs */
  caracterizacion_M->Sizes.numU = (0); /* Number of model inputs */
  caracterizacion_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  caracterizacion_M->Sizes.numSampTimes = (1);/* Number of sample times */
  caracterizacion_M->Sizes.numBlocks = (7);/* Number of blocks */
  caracterizacion_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  caracterizacion_M->Sizes.numBlockPrms = (10);/* Sum of parameter "widths" */
  return caracterizacion_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
