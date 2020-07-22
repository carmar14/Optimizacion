/*
 * ControladorContinuo_data.c
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

/* Block parameters (auto storage) */
Parameters_ControladorContinuo ControladorContinuo_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  23.630799082924717,                  /* Expression: -ki
                                        * Referenced by: '<Root>/-ki'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */

  /*  Expression: -kp
   * Referenced by: '<Root>/-kp'
   */
  { -2.3589074882082062, -0.00041754003513592237, -2.9803000482733668E-5 },
  0.0,                                 /* Expression: InitialValue
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  5.0,                                 /* Expression: FinalValue
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  5.0,                                 /* Expression: gain
                                        * Referenced by: '<S1>/Slider Gain'
                                        */

  /*  Expression: h
   * Referenced by: '<Root>/h'
   */
  { 15.99, -79074.0199, -949681.481201 },

  /*  Expression: b
   * Referenced by: '<Root>/b2'
   */
  { 7.711, -167.9, 63100.0 },

  /*  Expression: a-(h*c)
   * Referenced by: '<Root>/a-hc'
   */
  { -15.99, 79074.0199, 156781.48120100005, 1.0, 0.0, -79150.0, 0.0, 1.0, -14.01
  },
  0,                                   /* Expression: Channels
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Expression: RangeMode
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Expression: VoltRange
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Expression: Channels
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  0,                                   /* Expression: RangeMode
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  1                                    /* Expression: VoltRange
                                        * Referenced by: '<Root>/Analog Input'
                                        */
};
