/*
 * model1_11_full_private.h
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

#ifndef RTW_HEADER_model1_11_full_private_h_
#define RTW_HEADER_model1_11_full_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "model1_11_full.h"
#include "model1_11_full_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void model1_11_full_Leftwheel(real_T rtu_i, real_T rtu_w, real_T rtu_E,
  real_T rtu_Tm, B_Leftwheel_model1_11_full_T *localB);

/* private model entry point functions */
extern void model1_11_full_derivatives(void);

#endif                                /* RTW_HEADER_model1_11_full_private_h_ */
