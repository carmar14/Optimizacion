/*
 * Controlador_data.c
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

/* Block parameters (auto storage) */
Parameters_Controlador Controlador_P = {
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/integrador'
                                        */

  /*  Expression: [1 0]
   * Referenced by: '<Root>/integrador'
   */
  { 1.0, 0.0 },

  /*  Expression: [1 -1]
   * Referenced by: '<Root>/integrador'
   */
  { 1.0, -1.0 },
  0.21417685769656825,                 /* Expression: -kidis
                                        * Referenced by: '<Root>/-kidis'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */

  /*  Expression: -kpdis
   * Referenced by: '<Root>/-kpdis'
   */
  { -2.2447842012986263, -0.00017088130168745657, -2.700634473618596E-5 },
  0.0,                                 /* Expression: InitialValue
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  5.0,                                 /* Expression: FinalValue
                                        * Referenced by: '<Root>/Analog Output'
                                        */

  /*  Expression: hdis
   * Referenced by: '<Root>/hdis'
   */
  { -3.6652441178888089, 2900.5843744682384, 278392.237487767 },

  /*  Expression: bdis
   * Referenced by: '<Root>/bdis2'
   */
  { 0.077847029506116522, 0.60373728430966589, 237.58482010456558 },

  /*  Expression: adis-(hdis*cdis)
   * Referenced by: '<Root>/adis-hdiscdis'
   */
  { 4.5797556325024207, -2919.0257122890007, -279100.30726482783,
    0.0012188585192706776, -0.9263661351698893, -89.123293747569534,
    2.325808780522428E-5, 0.00089301270911948567, -0.93887724322465349 },
  0,                                   /* Expression: Channels
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  0,                                   /* Expression: RangeMode
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  1,                                   /* Expression: VoltRange
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  0,                                   /* Expression: Channels
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Expression: RangeMode
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0                                    /* Expression: VoltRange
                                        * Referenced by: '<Root>/Analog Output'
                                        */
};
