/*
 * model1_11_full_data.c
 *
 * Code generation for model "model1_11_full".
 *
 * Model version              : 1.15
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Sat Feb 11 02:53:14 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model1_11_full.h"

/* Block parameters (default storage) */
P_model1_11_full_T model1_11_full_P = {
  /* Variable: J
   * Referenced by:
   *   '<S3>/Left wheel'
   *   '<S4>/Right wheel'
   */
  0.2,

  /* Variable: Ke
   * Referenced by:
   *   '<Root>/Gain3'
   *   '<Root>/Gain4'
   *   '<S3>/Left wheel'
   *   '<S4>/Right wheel'
   */
  0.19,

  /* Variable: Km
   * Referenced by:
   *   '<Root>/Gain1'
   *   '<Root>/Gain2'
   *   '<Root>/Gain5'
   *   '<Root>/Gain6'
   *   '<S3>/Left wheel'
   *   '<S4>/Right wheel'
   */
  0.2613,

  /* Variable: L
   * Referenced by:
   *   '<S3>/Left wheel'
   *   '<S4>/Right wheel'
   */
  0.048,

  /* Variable: N
   * Referenced by:
   *   '<Root>/Gain1'
   *   '<Root>/Gain2'
   *   '<Root>/Gain5'
   *   '<Root>/Gain6'
   */
  62.55,

  /* Variable: R
   * Referenced by:
   *   '<S3>/Left wheel'
   *   '<S4>/Right wheel'
   */
  1.6,

  /* Variable: f
   * Referenced by:
   *   '<S3>/Left wheel'
   *   '<S4>/Right wheel'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator5'
   */
  0.0,

  /* Expression: 2*3.14/10
   * Referenced by: '<Root>/Gain'
   */
  0.628,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator6'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Integrator6'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<Root>/Integrator6'
   */
  -3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/P'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/P'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory3'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S3>/Constant2'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S4>/Memory2'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S4>/Constant'
   */
  0.3,

  /* Expression: 10
   * Referenced by: '<S5>/I'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<S6>/I'
   */
  10.0
};
