/*
 * model1_11_full.h
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

#ifndef RTW_HEADER_model1_11_full_h_
#define RTW_HEADER_model1_11_full_h_
#ifndef model1_11_full_COMMON_INCLUDES_
#define model1_11_full_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* model1_11_full_COMMON_INCLUDES_ */

#include "model1_11_full_types.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <float.h>
#include <math.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S3>/Left wheel' */
typedef struct {
  real_T Di;                           /* '<S3>/Left wheel' */
  real_T Dw;                           /* '<S3>/Left wheel' */
} B_Leftwheel_model1_11_full_T;

/* Block signals (default storage) */
typedef struct {
  real_T Fcn2;                         /* '<Root>/Fcn2' */
  real_T x;                            /* '<Root>/Integrator4' */
  real_T Xe;                           /* '<Root>/Sum1' */
  real_T Fcn3;                         /* '<Root>/Fcn3' */
  real_T y;                            /* '<Root>/Integrator5' */
  real_T Ye;                           /* '<Root>/Sum6' */
  real_T phi;                          /* '<Root>/Gain' */
  real_T Derivative1[2];               /* '<Root>/Derivative1' */
  real_T Velocity;                     /* '<Root>/Velocity' */
  real_T Fcn4;                         /* '<Root>/Fcn4' */
  real_T Derivative;                   /* '<Root>/Derivative' */
  real_T phi_m;                        /* '<Root>/Integrator6' */
  real_T w_right;                      /* '<S4>/Integrator3' */
  real_T i;                            /* '<S4>/Integrator2' */
  real_T i_h;                          /* '<S3>/Integrator4' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T w_right_l;                    /* '<S3>/Integrator5' */
  real_T Sum4;                         /* '<Root>/Sum4' */
  real_T Memory3;                      /* '<S3>/Memory3' */
  real_T Memory2;                      /* '<S4>/Memory2' */
  real_T I;                            /* '<S5>/I' */
  real_T I_l;                          /* '<S6>/I' */
  real_T vc;                           /* '<Root>/kinematic controller' */
  real_T wc;                           /* '<Root>/kinematic controller' */
  real_T vd;                           /* '<Root>/State feedback kinematic' */
  real_T wd;                           /* '<Root>/State feedback kinematic' */
  real_T Tr;                           /* '<Root>/State feedback dynamic' */
  real_T Tl;                           /* '<Root>/State feedback dynamic' */
  real_T Dx;                           /* '<Root>/Kinematic model' */
  real_T Dy;                           /* '<Root>/Kinematic model' */
  real_T Dphi;                         /* '<Root>/Kinematic model' */
  real_T Dv;                           /* '<Root>/Dynamic model' */
  real_T Dw;                           /* '<Root>/Dynamic model' */
  B_Leftwheel_model1_11_full_T sf_Rightwheel;/* '<S4>/Right wheel' */
  B_Leftwheel_model1_11_full_T sf_Leftwheel;/* '<S3>/Left wheel' */
} B_model1_11_full_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<Root>/Derivative1' */
  real_T LastUAtTimeA[2];              /* '<Root>/Derivative1' */
  real_T TimeStampB;                   /* '<Root>/Derivative1' */
  real_T LastUAtTimeB[2];              /* '<Root>/Derivative1' */
  real_T TimeStampA_m;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeA_h;               /* '<Root>/Derivative' */
  real_T TimeStampB_d;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeB_n;               /* '<Root>/Derivative' */
  real_T TimeStampA_p;                 /* '<Root>/Derivative6' */
  real_T LastUAtTimeA_d;               /* '<Root>/Derivative6' */
  real_T TimeStampB_b;                 /* '<Root>/Derivative6' */
  real_T LastUAtTimeB_o;               /* '<Root>/Derivative6' */
  real_T TimeStampA_k;                 /* '<Root>/Derivative7' */
  real_T LastUAtTimeA_m;               /* '<Root>/Derivative7' */
  real_T TimeStampB_bd;                /* '<Root>/Derivative7' */
  real_T LastUAtTimeB_a;               /* '<Root>/Derivative7' */
  real_T TimeStampA_l;                 /* '<Root>/Derivative4' */
  real_T LastUAtTimeA_b;               /* '<Root>/Derivative4' */
  real_T TimeStampB_bi;                /* '<Root>/Derivative4' */
  real_T LastUAtTimeB_m;               /* '<Root>/Derivative4' */
  real_T TimeStampA_kh;                /* '<Root>/Derivative5' */
  real_T LastUAtTimeA_g;               /* '<Root>/Derivative5' */
  real_T TimeStampB_g;                 /* '<Root>/Derivative5' */
  real_T LastUAtTimeB_i;               /* '<Root>/Derivative5' */
  real_T Memory3_PreviousInput;        /* '<S3>/Memory3' */
  real_T Memory2_PreviousInput;        /* '<S4>/Memory2' */
} DW_model1_11_full_T;

/* Continuous states (default storage) */
typedef struct {
  real_T x;                            /* '<Root>/Integrator4' */
  real_T y;                            /* '<Root>/Integrator5' */
  real_T Integrator6_CSTATE;           /* '<Root>/Integrator6' */
  real_T Integrator3_CSTATE;           /* '<S4>/Integrator3' */
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator4_CSTATE;           /* '<S3>/Integrator4' */
  real_T Integrator2_CSTATE_i;         /* '<S5>/Integrator2' */
  real_T Integrator2_CSTATE_o;         /* '<S6>/Integrator2' */
  real_T Integrator5_CSTATE;           /* '<S3>/Integrator5' */
} X_model1_11_full_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_model1_11_full_T[1];
typedef real_T PeriodicRngX_model1_11_full_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T x;                            /* '<Root>/Integrator4' */
  real_T y;                            /* '<Root>/Integrator5' */
  real_T Integrator6_CSTATE;           /* '<Root>/Integrator6' */
  real_T Integrator3_CSTATE;           /* '<S4>/Integrator3' */
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator4_CSTATE;           /* '<S3>/Integrator4' */
  real_T Integrator2_CSTATE_i;         /* '<S5>/Integrator2' */
  real_T Integrator2_CSTATE_o;         /* '<S6>/Integrator2' */
  real_T Integrator5_CSTATE;           /* '<S3>/Integrator5' */
} XDot_model1_11_full_T;

/* State disabled  */
typedef struct {
  boolean_T x;                         /* '<Root>/Integrator4' */
  boolean_T y;                         /* '<Root>/Integrator5' */
  boolean_T Integrator6_CSTATE;        /* '<Root>/Integrator6' */
  boolean_T Integrator3_CSTATE;        /* '<S4>/Integrator3' */
  boolean_T Integrator2_CSTATE;        /* '<S4>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator4_CSTATE;        /* '<S3>/Integrator4' */
  boolean_T Integrator2_CSTATE_i;      /* '<S5>/Integrator2' */
  boolean_T Integrator2_CSTATE_o;      /* '<S6>/Integrator2' */
  boolean_T Integrator5_CSTATE;        /* '<S3>/Integrator5' */
} XDis_model1_11_full_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_model1_11_full_T_ {
  real_T J;                            /* Variable: J
                                        * Referenced by:
                                        *   '<S3>/Left wheel'
                                        *   '<S4>/Right wheel'
                                        */
  real_T Ke;                           /* Variable: Ke
                                        * Referenced by:
                                        *   '<Root>/Gain3'
                                        *   '<Root>/Gain4'
                                        *   '<S3>/Left wheel'
                                        *   '<S4>/Right wheel'
                                        */
  real_T Km;                           /* Variable: Km
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain2'
                                        *   '<Root>/Gain5'
                                        *   '<Root>/Gain6'
                                        *   '<S3>/Left wheel'
                                        *   '<S4>/Right wheel'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by:
                                        *   '<S3>/Left wheel'
                                        *   '<S4>/Right wheel'
                                        */
  real_T N;                            /* Variable: N
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain2'
                                        *   '<Root>/Gain5'
                                        *   '<Root>/Gain6'
                                        */
  real_T R;                            /* Variable: R
                                        * Referenced by:
                                        *   '<S3>/Left wheel'
                                        *   '<S4>/Right wheel'
                                        */
  real_T f;                            /* Variable: f
                                        * Referenced by:
                                        *   '<S3>/Left wheel'
                                        *   '<S4>/Right wheel'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator5'
                                        */
  real_T Gain_Gain;                    /* Expression: 2*3.14/10
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator6'
                                        */
  real_T Integrator6_WrappedStateUpperVa;/* Expression: pi
                                          * Referenced by: '<Root>/Integrator6'
                                          */
  real_T Integrator6_WrappedStateLowerVa;/* Expression: -pi
                                          * Referenced by: '<Root>/Integrator6'
                                          */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator3'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator4_IC_k;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator4'
                                        */
  real_T P_Gain;                       /* Expression: 1
                                        * Referenced by: '<S5>/P'
                                        */
  real_T Integrator2_IC_e;             /* Expression: 0
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T P_Gain_g;                     /* Expression: 1
                                        * Referenced by: '<S6>/P'
                                        */
  real_T Integrator2_IC_m;             /* Expression: 0
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T Integrator5_IC_i;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator5'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory3'
                                        */
  real_T Constant2_Value;              /* Expression: 0.3
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Constant_Value;               /* Expression: 0.3
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T I_Gain;                       /* Expression: 10
                                        * Referenced by: '<S5>/I'
                                        */
  real_T I_Gain_n;                     /* Expression: 10
                                        * Referenced by: '<S6>/I'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_model1_11_full_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_model1_11_full_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_model1_11_full_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[11];
  real_T odeF[3][11];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_model1_11_full_T model1_11_full_P;

/* Block signals (default storage) */
extern B_model1_11_full_T model1_11_full_B;

/* Continuous states (default storage) */
extern X_model1_11_full_T model1_11_full_X;

/* Block states (default storage) */
extern DW_model1_11_full_T model1_11_full_DW;

/* Model entry point functions */
extern void model1_11_full_initialize(void);
extern void model1_11_full_step(void);
extern void model1_11_full_terminate(void);

/* Real-time Model object */
extern RT_MODEL_model1_11_full_T *const model1_11_full_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'model1_11_full'
 * '<S1>'   : 'model1_11_full/Dynamic model'
 * '<S2>'   : 'model1_11_full/Kinematic model'
 * '<S3>'   : 'model1_11_full/Motor left'
 * '<S4>'   : 'model1_11_full/Motor right'
 * '<S5>'   : 'model1_11_full/PI 1'
 * '<S6>'   : 'model1_11_full/PI 2'
 * '<S7>'   : 'model1_11_full/State feedback dynamic'
 * '<S8>'   : 'model1_11_full/State feedback kinematic'
 * '<S9>'   : 'model1_11_full/kinematic controller'
 * '<S10>'  : 'model1_11_full/Motor left/Left wheel'
 * '<S11>'  : 'model1_11_full/Motor right/Right wheel'
 */
#endif                                 /* RTW_HEADER_model1_11_full_h_ */
