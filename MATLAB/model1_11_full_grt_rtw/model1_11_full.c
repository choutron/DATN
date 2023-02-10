/*
 * model1_11_full.c
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
#include "rtwtypes.h"
#include "model1_11_full_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <string.h>

/* Block signals (default storage) */
B_model1_11_full_T model1_11_full_B;

/* Continuous states */
X_model1_11_full_T model1_11_full_X;

/* Block states (default storage) */
DW_model1_11_full_T model1_11_full_DW;

/* Periodic continuous states */
PeriodicIndX_model1_11_full_T model1_11_full_PeriodicIndX;
PeriodicRngX_model1_11_full_T model1_11_full_PeriodicRngX;

/* Real-time model */
static RT_MODEL_model1_11_full_T model1_11_full_M_;
RT_MODEL_model1_11_full_T *const model1_11_full_M = &model1_11_full_M_;

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 11;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  model1_11_full_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  model1_11_full_step();
  model1_11_full_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  model1_11_full_step();
  model1_11_full_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       1,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S3>/Left wheel'
 *    '<S4>/Right wheel'
 */
void model1_11_full_Leftwheel(real_T rtu_i, real_T rtu_w, real_T rtu_E, real_T
  rtu_Tm, B_Leftwheel_model1_11_full_T *localB)
{
  localB->Di = ((rtu_E - model1_11_full_P.R * rtu_i) - model1_11_full_P.Ke *
                rtu_w) / model1_11_full_P.L;
  localB->Dw = ((rtu_Tm - model1_11_full_P.f * rtu_w) - model1_11_full_P.Km *
                rtu_i) / model1_11_full_P.J;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void model1_11_full_step(void)
{
  if (rtmIsMajorTimeStep(model1_11_full_M)) {
    /* set solver stop time */
    if (!(model1_11_full_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&model1_11_full_M->solverInfo,
                            ((model1_11_full_M->Timing.clockTickH0 + 1) *
        model1_11_full_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&model1_11_full_M->solverInfo,
                            ((model1_11_full_M->Timing.clockTick0 + 1) *
        model1_11_full_M->Timing.stepSize0 +
        model1_11_full_M->Timing.clockTickH0 *
        model1_11_full_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(model1_11_full_M)) {
    model1_11_full_M->Timing.t[0] = rtsiGetT(&model1_11_full_M->solverInfo);
  }

  {
    real_T (*lastU)[2];
    real_T V_tmp;
    real_T Xe_tmp;
    real_T Ye_tmp;
    real_T phie;
    real_T rtb_Derivative5;
    real_T rtb_Derivative6;
    real_T rtb_Derivative7;
    real_T *lastU_0;

    /* Clock: '<Root>/Clock' incorporates:
     *  Derivative: '<Root>/Derivative'
     *  Derivative: '<Root>/Derivative1'
     *  Derivative: '<Root>/Derivative4'
     *  Derivative: '<Root>/Derivative5'
     *  Derivative: '<Root>/Derivative6'
     *  Derivative: '<Root>/Derivative7'
     */
    rtb_Derivative5 = model1_11_full_M->Timing.t[0];

    /* Fcn: '<Root>/Fcn2' incorporates:
     *  Clock: '<Root>/Clock'
     */
    model1_11_full_B.Fcn2 = sin(0.20933333333333334 * rtb_Derivative5) * 0.7 +
      1.1;

    /* Integrator: '<Root>/Integrator4' */
    model1_11_full_B.x = model1_11_full_X.x;

    /* Sum: '<Root>/Sum1' incorporates:
     *  MATLAB Function: '<Root>/State feedback kinematic'
     *  MATLAB Function: '<Root>/kinematic controller'
     */
    Xe_tmp = model1_11_full_B.Fcn2 - model1_11_full_B.x;

    /* Sum: '<Root>/Sum1' */
    model1_11_full_B.Xe = Xe_tmp;

    /* Fcn: '<Root>/Fcn3' incorporates:
     *  Clock: '<Root>/Clock'
     */
    model1_11_full_B.Fcn3 = sin(0.41866666666666669 * rtb_Derivative5) * 2.0 +
      0.9;

    /* Integrator: '<Root>/Integrator5' */
    model1_11_full_B.y = model1_11_full_X.y;

    /* Sum: '<Root>/Sum6' incorporates:
     *  MATLAB Function: '<Root>/State feedback kinematic'
     *  MATLAB Function: '<Root>/kinematic controller'
     */
    Ye_tmp = model1_11_full_B.Fcn3 - model1_11_full_B.y;

    /* Sum: '<Root>/Sum6' */
    model1_11_full_B.Ye = Ye_tmp;
    if (rtmIsMajorTimeStep(model1_11_full_M)) {
    }

    /* Gain: '<Root>/Gain' incorporates:
     *  Clock: '<Root>/Clock'
     */
    model1_11_full_B.phi = model1_11_full_P.Gain_Gain * rtb_Derivative5;

    /* Derivative: '<Root>/Derivative1' */
    if ((model1_11_full_DW.TimeStampA >= rtb_Derivative5) &&
        (model1_11_full_DW.TimeStampB >= rtb_Derivative5)) {
      /* Derivative: '<Root>/Derivative1' */
      model1_11_full_B.Derivative1[0] = 0.0;
      model1_11_full_B.Derivative1[1] = 0.0;
    } else {
      rtb_Derivative7 = model1_11_full_DW.TimeStampA;
      lastU = &model1_11_full_DW.LastUAtTimeA;
      if (model1_11_full_DW.TimeStampA < model1_11_full_DW.TimeStampB) {
        if (model1_11_full_DW.TimeStampB < rtb_Derivative5) {
          rtb_Derivative7 = model1_11_full_DW.TimeStampB;
          lastU = &model1_11_full_DW.LastUAtTimeB;
        }
      } else if (model1_11_full_DW.TimeStampA >= rtb_Derivative5) {
        rtb_Derivative7 = model1_11_full_DW.TimeStampB;
        lastU = &model1_11_full_DW.LastUAtTimeB;
      }

      phie = rtb_Derivative5 - rtb_Derivative7;

      /* Derivative: '<Root>/Derivative1' */
      model1_11_full_B.Derivative1[0] = (model1_11_full_B.Fcn2 - (*lastU)[0]) /
        phie;
      model1_11_full_B.Derivative1[1] = (model1_11_full_B.Fcn3 - (*lastU)[1]) /
        phie;
    }

    /* Fcn: '<Root>/Velocity' */
    model1_11_full_B.Velocity = sqrt(rt_powd_snf(model1_11_full_B.Derivative1[0],
      2.0) + rt_powd_snf(model1_11_full_B.Derivative1[1], 2.0));
    if (rtmIsMajorTimeStep(model1_11_full_M)) {
    }

    /* Fcn: '<Root>/Fcn4' */
    model1_11_full_B.Fcn4 = rt_atan2d_snf(model1_11_full_B.Derivative1[1],
      model1_11_full_B.Derivative1[0]);

    /* Derivative: '<Root>/Derivative' */
    if ((model1_11_full_DW.TimeStampA_m >= rtb_Derivative5) &&
        (model1_11_full_DW.TimeStampB_d >= rtb_Derivative5)) {
      /* Derivative: '<Root>/Derivative' */
      model1_11_full_B.Derivative = 0.0;
    } else {
      rtb_Derivative7 = model1_11_full_DW.TimeStampA_m;
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_h;
      if (model1_11_full_DW.TimeStampA_m < model1_11_full_DW.TimeStampB_d) {
        if (model1_11_full_DW.TimeStampB_d < rtb_Derivative5) {
          rtb_Derivative7 = model1_11_full_DW.TimeStampB_d;
          lastU_0 = &model1_11_full_DW.LastUAtTimeB_n;
        }
      } else if (model1_11_full_DW.TimeStampA_m >= rtb_Derivative5) {
        rtb_Derivative7 = model1_11_full_DW.TimeStampB_d;
        lastU_0 = &model1_11_full_DW.LastUAtTimeB_n;
      }

      /* Derivative: '<Root>/Derivative' */
      model1_11_full_B.Derivative = (model1_11_full_B.Fcn4 - *lastU_0) /
        (rtb_Derivative5 - rtb_Derivative7);
    }

    /* Integrator: '<Root>/Integrator6' */
    model1_11_full_B.phi_m = model1_11_full_X.Integrator6_CSTATE;

    /* MATLAB Function: '<Root>/kinematic controller' */
    phie = model1_11_full_B.Fcn4 - model1_11_full_B.phi_m;
    model1_11_full_B.vc = Xe_tmp * 0.001 + model1_11_full_B.Velocity * cos(phie);
    model1_11_full_B.wc = (Ye_tmp * 0.01 + 0.0001 * sin(phie)) *
      model1_11_full_B.Velocity + model1_11_full_B.Derivative;
    if (rtmIsMajorTimeStep(model1_11_full_M)) {
    }

    /* Integrator: '<S4>/Integrator3' */
    model1_11_full_B.w_right = model1_11_full_X.Integrator3_CSTATE;

    /* Integrator: '<S4>/Integrator2' */
    model1_11_full_B.i = model1_11_full_X.Integrator2_CSTATE;

    /* Derivative: '<Root>/Derivative6' */
    if ((model1_11_full_DW.TimeStampA_p >= rtb_Derivative5) &&
        (model1_11_full_DW.TimeStampB_b >= rtb_Derivative5)) {
      rtb_Derivative6 = 0.0;
    } else {
      rtb_Derivative7 = model1_11_full_DW.TimeStampA_p;
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_d;
      if (model1_11_full_DW.TimeStampA_p < model1_11_full_DW.TimeStampB_b) {
        if (model1_11_full_DW.TimeStampB_b < rtb_Derivative5) {
          rtb_Derivative7 = model1_11_full_DW.TimeStampB_b;
          lastU_0 = &model1_11_full_DW.LastUAtTimeB_o;
        }
      } else if (model1_11_full_DW.TimeStampA_p >= rtb_Derivative5) {
        rtb_Derivative7 = model1_11_full_DW.TimeStampB_b;
        lastU_0 = &model1_11_full_DW.LastUAtTimeB_o;
      }

      rtb_Derivative6 = (model1_11_full_B.Fcn2 - *lastU_0) / (rtb_Derivative5 -
        rtb_Derivative7);
    }

    /* Derivative: '<Root>/Derivative7' */
    if ((model1_11_full_DW.TimeStampA_k >= rtb_Derivative5) &&
        (model1_11_full_DW.TimeStampB_bd >= rtb_Derivative5)) {
      rtb_Derivative7 = 0.0;
    } else {
      rtb_Derivative7 = model1_11_full_DW.TimeStampA_k;
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_m;
      if (model1_11_full_DW.TimeStampA_k < model1_11_full_DW.TimeStampB_bd) {
        if (model1_11_full_DW.TimeStampB_bd < rtb_Derivative5) {
          rtb_Derivative7 = model1_11_full_DW.TimeStampB_bd;
          lastU_0 = &model1_11_full_DW.LastUAtTimeB_a;
        }
      } else if (model1_11_full_DW.TimeStampA_k >= rtb_Derivative5) {
        rtb_Derivative7 = model1_11_full_DW.TimeStampB_bd;
        lastU_0 = &model1_11_full_DW.LastUAtTimeB_a;
      }

      rtb_Derivative7 = (model1_11_full_B.Fcn3 - *lastU_0) / (rtb_Derivative5 -
        rtb_Derivative7);
    }

    /* MATLAB Function: '<Root>/State feedback kinematic' incorporates:
     *  MATLAB Function: '<Root>/Kinematic model'
     */
    phie = sin(model1_11_full_B.phi_m);
    V_tmp = cos(model1_11_full_B.phi_m);
    rtb_Derivative6 += 0.0 * Ye_tmp + Xe_tmp;
    rtb_Derivative7 += 0.0 * Xe_tmp + Ye_tmp;
    model1_11_full_B.vd = V_tmp * rtb_Derivative6 + phie * rtb_Derivative7;
    model1_11_full_B.wd = -phie / 0.3 * rtb_Derivative6 + V_tmp / 0.3 *
      rtb_Derivative7;

    /* Gain: '<Root>/Gain1' incorporates:
     *  Gain: '<Root>/Gain2'
     */
    rtb_Derivative6 = model1_11_full_P.N * model1_11_full_P.Km;
    rtb_Derivative7 = rtb_Derivative6 * model1_11_full_B.i;

    /* Integrator: '<S3>/Integrator4' */
    model1_11_full_B.i_h = model1_11_full_X.Integrator4_CSTATE;

    /* Gain: '<Root>/Gain2' */
    rtb_Derivative6 *= model1_11_full_B.i_h;

    /* MATLAB Function: '<Root>/Dynamic model' incorporates:
     *  Integrator: '<Root>/Integrator'
     *  Integrator: '<Root>/Integrator1'
     *  MATLAB Function: '<Root>/State feedback dynamic'
     */
    Xe_tmp = model1_11_full_X.Integrator1_CSTATE *
      model1_11_full_X.Integrator1_CSTATE * 9.0;
    model1_11_full_B.Dv = ((rtb_Derivative7 + rtb_Derivative6) / 0.15 + Xe_tmp) /
      32.444444444444443;
    Ye_tmp = 9.0 * model1_11_full_X.Integrator1_CSTATE *
      model1_11_full_X.Integrator_CSTATE;
    model1_11_full_B.Dw = ((rtb_Derivative7 - rtb_Derivative6) * 0.375 / 0.15 -
      Ye_tmp) / 18.67375;

    /* Derivative: '<Root>/Derivative4' */
    if ((model1_11_full_DW.TimeStampA_l >= rtb_Derivative5) &&
        (model1_11_full_DW.TimeStampB_bi >= rtb_Derivative5)) {
      rtb_Derivative6 = 0.0;
    } else {
      rtb_Derivative7 = model1_11_full_DW.TimeStampA_l;
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_b;
      if (model1_11_full_DW.TimeStampA_l < model1_11_full_DW.TimeStampB_bi) {
        if (model1_11_full_DW.TimeStampB_bi < rtb_Derivative5) {
          rtb_Derivative7 = model1_11_full_DW.TimeStampB_bi;
          lastU_0 = &model1_11_full_DW.LastUAtTimeB_m;
        }
      } else if (model1_11_full_DW.TimeStampA_l >= rtb_Derivative5) {
        rtb_Derivative7 = model1_11_full_DW.TimeStampB_bi;
        lastU_0 = &model1_11_full_DW.LastUAtTimeB_m;
      }

      rtb_Derivative6 = (model1_11_full_B.vd - *lastU_0) / (rtb_Derivative5 -
        rtb_Derivative7);
    }

    /* Derivative: '<Root>/Derivative5' */
    if ((model1_11_full_DW.TimeStampA_kh >= rtb_Derivative5) &&
        (model1_11_full_DW.TimeStampB_g >= rtb_Derivative5)) {
      rtb_Derivative5 = 0.0;
    } else {
      rtb_Derivative7 = model1_11_full_DW.TimeStampA_kh;
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_g;
      if (model1_11_full_DW.TimeStampA_kh < model1_11_full_DW.TimeStampB_g) {
        if (model1_11_full_DW.TimeStampB_g < rtb_Derivative5) {
          rtb_Derivative7 = model1_11_full_DW.TimeStampB_g;
          lastU_0 = &model1_11_full_DW.LastUAtTimeB_i;
        }
      } else if (model1_11_full_DW.TimeStampA_kh >= rtb_Derivative5) {
        rtb_Derivative7 = model1_11_full_DW.TimeStampB_g;
        lastU_0 = &model1_11_full_DW.LastUAtTimeB_i;
      }

      rtb_Derivative5 = (model1_11_full_B.wd - *lastU_0) / (rtb_Derivative5 -
        rtb_Derivative7);
    }

    /* MATLAB Function: '<Root>/State feedback dynamic' incorporates:
     *  Integrator: '<Root>/Integrator'
     *  Integrator: '<Root>/Integrator1'
     */
    rtb_Derivative7 = (((model1_11_full_B.vd -
                         model1_11_full_X.Integrator_CSTATE) * 25.0 +
                        rtb_Derivative6) * 32.444444444444443 - Xe_tmp) * 0.15;
    rtb_Derivative5 = (((model1_11_full_B.wd -
                         model1_11_full_X.Integrator1_CSTATE) * 25.0 +
                        rtb_Derivative5) * 18.67375 + Ye_tmp) *
      0.39999999999999997;
    model1_11_full_B.Tr = (rtb_Derivative7 + rtb_Derivative5) / 2.0;
    model1_11_full_B.Tl = (rtb_Derivative7 - rtb_Derivative5) / 2.0;

    /* Gain: '<Root>/Gain5' incorporates:
     *  Gain: '<Root>/Gain6'
     */
    rtb_Derivative7 = 1.0 / model1_11_full_P.N / model1_11_full_P.Km;

    /* Sum: '<Root>/Sum2' incorporates:
     *  Gain: '<Root>/Gain5'
     */
    rtb_Derivative5 = rtb_Derivative7 * model1_11_full_B.Tr - model1_11_full_B.i;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Gain: '<Root>/Gain3'
     *  Gain: '<S5>/P'
     *  Integrator: '<S5>/Integrator2'
     *  Sum: '<S5>/Sum1'
     */
    model1_11_full_B.Sum3 = (model1_11_full_P.P_Gain * rtb_Derivative5 +
      model1_11_full_X.Integrator2_CSTATE_i) + model1_11_full_P.Ke *
      model1_11_full_B.w_right;

    /* Sum: '<Root>/Sum5' incorporates:
     *  Gain: '<Root>/Gain6'
     */
    rtb_Derivative7 = rtb_Derivative7 * model1_11_full_B.Tl -
      model1_11_full_B.i_h;

    /* Integrator: '<S3>/Integrator5' */
    model1_11_full_B.w_right_l = model1_11_full_X.Integrator5_CSTATE;

    /* Sum: '<Root>/Sum4' incorporates:
     *  Gain: '<Root>/Gain4'
     *  Gain: '<S6>/P'
     *  Integrator: '<S6>/Integrator2'
     *  Sum: '<S6>/Sum1'
     */
    model1_11_full_B.Sum4 = (model1_11_full_P.P_Gain_g * rtb_Derivative7 +
      model1_11_full_X.Integrator2_CSTATE_o) + model1_11_full_P.Ke *
      model1_11_full_B.w_right_l;
    if (rtmIsMajorTimeStep(model1_11_full_M)) {
    }

    /* MATLAB Function: '<Root>/Kinematic model' incorporates:
     *  Integrator: '<Root>/Integrator'
     *  Integrator: '<Root>/Integrator1'
     */
    model1_11_full_B.Dx = model1_11_full_X.Integrator_CSTATE * V_tmp - 0.3 *
      model1_11_full_X.Integrator1_CSTATE * phie;
    model1_11_full_B.Dy = 0.3 * model1_11_full_X.Integrator1_CSTATE * V_tmp +
      model1_11_full_X.Integrator_CSTATE * phie;
    model1_11_full_B.Dphi = model1_11_full_X.Integrator1_CSTATE;
    if (rtmIsMajorTimeStep(model1_11_full_M)) {
      /* Memory: '<S3>/Memory3' */
      model1_11_full_B.Memory3 = model1_11_full_DW.Memory3_PreviousInput;
    }

    /* MATLAB Function: '<S3>/Left wheel' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    model1_11_full_Leftwheel(model1_11_full_B.i_h, model1_11_full_B.w_right_l,
      model1_11_full_B.Memory3, model1_11_full_P.Constant2_Value,
      &model1_11_full_B.sf_Leftwheel);
    if (rtmIsMajorTimeStep(model1_11_full_M)) {
      /* Memory: '<S4>/Memory2' */
      model1_11_full_B.Memory2 = model1_11_full_DW.Memory2_PreviousInput;
    }

    /* MATLAB Function: '<S4>/Right wheel' incorporates:
     *  Constant: '<S4>/Constant'
     */
    model1_11_full_Leftwheel(model1_11_full_B.i, model1_11_full_B.w_right,
      model1_11_full_B.Memory2, model1_11_full_P.Constant_Value,
      &model1_11_full_B.sf_Rightwheel);

    /* Gain: '<S5>/I' */
    model1_11_full_B.I = model1_11_full_P.I_Gain * rtb_Derivative5;

    /* Gain: '<S6>/I' */
    model1_11_full_B.I_l = model1_11_full_P.I_Gain_n * rtb_Derivative7;
  }

  if (rtmIsMajorTimeStep(model1_11_full_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(model1_11_full_M->rtwLogInfo,
                        (model1_11_full_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(model1_11_full_M)) {
    real_T (*lastU)[2];
    real_T *lastU_0;

    /* Update for Derivative: '<Root>/Derivative1' */
    if (model1_11_full_DW.TimeStampA == (rtInf)) {
      model1_11_full_DW.TimeStampA = model1_11_full_M->Timing.t[0];
      lastU = &model1_11_full_DW.LastUAtTimeA;
    } else if (model1_11_full_DW.TimeStampB == (rtInf)) {
      model1_11_full_DW.TimeStampB = model1_11_full_M->Timing.t[0];
      lastU = &model1_11_full_DW.LastUAtTimeB;
    } else if (model1_11_full_DW.TimeStampA < model1_11_full_DW.TimeStampB) {
      model1_11_full_DW.TimeStampA = model1_11_full_M->Timing.t[0];
      lastU = &model1_11_full_DW.LastUAtTimeA;
    } else {
      model1_11_full_DW.TimeStampB = model1_11_full_M->Timing.t[0];
      lastU = &model1_11_full_DW.LastUAtTimeB;
    }

    (*lastU)[0] = model1_11_full_B.Fcn2;
    (*lastU)[1] = model1_11_full_B.Fcn3;

    /* End of Update for Derivative: '<Root>/Derivative1' */

    /* Update for Derivative: '<Root>/Derivative' */
    if (model1_11_full_DW.TimeStampA_m == (rtInf)) {
      model1_11_full_DW.TimeStampA_m = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_h;
    } else if (model1_11_full_DW.TimeStampB_d == (rtInf)) {
      model1_11_full_DW.TimeStampB_d = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_n;
    } else if (model1_11_full_DW.TimeStampA_m < model1_11_full_DW.TimeStampB_d)
    {
      model1_11_full_DW.TimeStampA_m = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_h;
    } else {
      model1_11_full_DW.TimeStampB_d = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_n;
    }

    *lastU_0 = model1_11_full_B.Fcn4;

    /* End of Update for Derivative: '<Root>/Derivative' */

    /* Update for Derivative: '<Root>/Derivative6' */
    if (model1_11_full_DW.TimeStampA_p == (rtInf)) {
      model1_11_full_DW.TimeStampA_p = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_d;
    } else if (model1_11_full_DW.TimeStampB_b == (rtInf)) {
      model1_11_full_DW.TimeStampB_b = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_o;
    } else if (model1_11_full_DW.TimeStampA_p < model1_11_full_DW.TimeStampB_b)
    {
      model1_11_full_DW.TimeStampA_p = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_d;
    } else {
      model1_11_full_DW.TimeStampB_b = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_o;
    }

    *lastU_0 = model1_11_full_B.Fcn2;

    /* End of Update for Derivative: '<Root>/Derivative6' */

    /* Update for Derivative: '<Root>/Derivative7' */
    if (model1_11_full_DW.TimeStampA_k == (rtInf)) {
      model1_11_full_DW.TimeStampA_k = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_m;
    } else if (model1_11_full_DW.TimeStampB_bd == (rtInf)) {
      model1_11_full_DW.TimeStampB_bd = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_a;
    } else if (model1_11_full_DW.TimeStampA_k < model1_11_full_DW.TimeStampB_bd)
    {
      model1_11_full_DW.TimeStampA_k = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_m;
    } else {
      model1_11_full_DW.TimeStampB_bd = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_a;
    }

    *lastU_0 = model1_11_full_B.Fcn3;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative4' */
    if (model1_11_full_DW.TimeStampA_l == (rtInf)) {
      model1_11_full_DW.TimeStampA_l = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_b;
    } else if (model1_11_full_DW.TimeStampB_bi == (rtInf)) {
      model1_11_full_DW.TimeStampB_bi = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_m;
    } else if (model1_11_full_DW.TimeStampA_l < model1_11_full_DW.TimeStampB_bi)
    {
      model1_11_full_DW.TimeStampA_l = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_b;
    } else {
      model1_11_full_DW.TimeStampB_bi = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_m;
    }

    *lastU_0 = model1_11_full_B.vd;

    /* End of Update for Derivative: '<Root>/Derivative4' */

    /* Update for Derivative: '<Root>/Derivative5' */
    if (model1_11_full_DW.TimeStampA_kh == (rtInf)) {
      model1_11_full_DW.TimeStampA_kh = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_g;
    } else if (model1_11_full_DW.TimeStampB_g == (rtInf)) {
      model1_11_full_DW.TimeStampB_g = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_i;
    } else if (model1_11_full_DW.TimeStampA_kh < model1_11_full_DW.TimeStampB_g)
    {
      model1_11_full_DW.TimeStampA_kh = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeA_g;
    } else {
      model1_11_full_DW.TimeStampB_g = model1_11_full_M->Timing.t[0];
      lastU_0 = &model1_11_full_DW.LastUAtTimeB_i;
    }

    *lastU_0 = model1_11_full_B.wd;

    /* End of Update for Derivative: '<Root>/Derivative5' */
    if (rtmIsMajorTimeStep(model1_11_full_M)) {
      /* Update for Memory: '<S3>/Memory3' */
      model1_11_full_DW.Memory3_PreviousInput = model1_11_full_B.Sum4;

      /* Update for Memory: '<S4>/Memory2' */
      model1_11_full_DW.Memory2_PreviousInput = model1_11_full_B.Sum3;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(model1_11_full_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(model1_11_full_M)!=-1) &&
          !((rtmGetTFinal(model1_11_full_M)-
             (((model1_11_full_M->Timing.clockTick1+
                model1_11_full_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((model1_11_full_M->Timing.clockTick1+
               model1_11_full_M->Timing.clockTickH1* 4294967296.0)) * 0.01) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(model1_11_full_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&model1_11_full_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++model1_11_full_M->Timing.clockTick0)) {
      ++model1_11_full_M->Timing.clockTickH0;
    }

    model1_11_full_M->Timing.t[0] = rtsiGetSolverStopTime
      (&model1_11_full_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      model1_11_full_M->Timing.clockTick1++;
      if (!model1_11_full_M->Timing.clockTick1) {
        model1_11_full_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void model1_11_full_derivatives(void)
{
  XDot_model1_11_full_T *_rtXdot;
  _rtXdot = ((XDot_model1_11_full_T *) model1_11_full_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator4' */
  _rtXdot->x = model1_11_full_B.Dx;

  /* Derivatives for Integrator: '<Root>/Integrator5' */
  _rtXdot->y = model1_11_full_B.Dy;

  /* Derivatives for Integrator: '<Root>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = model1_11_full_B.Dphi;

  /* Derivatives for Integrator: '<S4>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = model1_11_full_B.sf_Rightwheel.Dw;

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = model1_11_full_B.sf_Rightwheel.Di;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = model1_11_full_B.Dv;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = model1_11_full_B.Dw;

  /* Derivatives for Integrator: '<S3>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = model1_11_full_B.sf_Leftwheel.Di;

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_i = model1_11_full_B.I;

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_o = model1_11_full_B.I_l;

  /* Derivatives for Integrator: '<S3>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = model1_11_full_B.sf_Leftwheel.Dw;
}

/* Model initialize function */
void model1_11_full_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model1_11_full_M, 0,
                sizeof(RT_MODEL_model1_11_full_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model1_11_full_M->solverInfo,
                          &model1_11_full_M->Timing.simTimeStep);
    rtsiSetTPtr(&model1_11_full_M->solverInfo, &rtmGetTPtr(model1_11_full_M));
    rtsiSetStepSizePtr(&model1_11_full_M->solverInfo,
                       &model1_11_full_M->Timing.stepSize0);
    rtsiSetdXPtr(&model1_11_full_M->solverInfo, &model1_11_full_M->derivs);
    rtsiSetContStatesPtr(&model1_11_full_M->solverInfo, (real_T **)
                         &model1_11_full_M->contStates);
    rtsiSetNumContStatesPtr(&model1_11_full_M->solverInfo,
      &model1_11_full_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&model1_11_full_M->solverInfo,
      &model1_11_full_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&model1_11_full_M->solverInfo,
      &model1_11_full_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&model1_11_full_M->solverInfo,
      &model1_11_full_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&model1_11_full_M->solverInfo, (&rtmGetErrorStatus
      (model1_11_full_M)));
    rtsiSetRTModelPtr(&model1_11_full_M->solverInfo, model1_11_full_M);
  }

  rtsiSetSimTimeStep(&model1_11_full_M->solverInfo, MAJOR_TIME_STEP);
  model1_11_full_M->intgData.y = model1_11_full_M->odeY;
  model1_11_full_M->intgData.f[0] = model1_11_full_M->odeF[0];
  model1_11_full_M->intgData.f[1] = model1_11_full_M->odeF[1];
  model1_11_full_M->intgData.f[2] = model1_11_full_M->odeF[2];
  model1_11_full_M->contStates = ((X_model1_11_full_T *) &model1_11_full_X);
  model1_11_full_M->periodicContStateIndices = ((int_T*)
    model1_11_full_PeriodicIndX);
  model1_11_full_M->periodicContStateRanges = ((real_T*)
    model1_11_full_PeriodicRngX);
  rtsiSetSolverData(&model1_11_full_M->solverInfo, (void *)
                    &model1_11_full_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&model1_11_full_M->solverInfo, false);
  rtsiSetSolverName(&model1_11_full_M->solverInfo,"ode3");
  rtmSetTPtr(model1_11_full_M, &model1_11_full_M->Timing.tArray[0]);
  rtmSetTFinal(model1_11_full_M, 31.0);
  model1_11_full_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    model1_11_full_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(model1_11_full_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(model1_11_full_M->rtwLogInfo, (NULL));
    rtliSetLogT(model1_11_full_M->rtwLogInfo, "tout");
    rtliSetLogX(model1_11_full_M->rtwLogInfo, "");
    rtliSetLogXFinal(model1_11_full_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(model1_11_full_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(model1_11_full_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(model1_11_full_M->rtwLogInfo, 0);
    rtliSetLogDecimation(model1_11_full_M->rtwLogInfo, 1);
    rtliSetLogY(model1_11_full_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(model1_11_full_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(model1_11_full_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &model1_11_full_B), 0,
                sizeof(B_model1_11_full_T));

  /* states (continuous) */
  {
    (void) memset((void *)&model1_11_full_X, 0,
                  sizeof(X_model1_11_full_T));
  }

  /* Periodic continuous states */
  {
    (void) memset((void*) model1_11_full_PeriodicIndX, 0,
                  1*sizeof(int_T));
    (void) memset((void*) model1_11_full_PeriodicRngX, 0,
                  2*sizeof(real_T));
  }

  /* states (dwork) */
  (void) memset((void *)&model1_11_full_DW, 0,
                sizeof(DW_model1_11_full_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(model1_11_full_M->rtwLogInfo, 0.0,
    rtmGetTFinal(model1_11_full_M), model1_11_full_M->Timing.stepSize0,
    (&rtmGetErrorStatus(model1_11_full_M)));

  /* InitializeConditions for Integrator: '<Root>/Integrator4' */
  model1_11_full_X.x = model1_11_full_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator5' */
  model1_11_full_X.y = model1_11_full_P.Integrator5_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  model1_11_full_DW.TimeStampA = (rtInf);
  model1_11_full_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  model1_11_full_DW.TimeStampA_m = (rtInf);
  model1_11_full_DW.TimeStampB_d = (rtInf);

  /* InitializeConditions for Integrator: '<Root>/Integrator6' */
  model1_11_full_X.Integrator6_CSTATE = model1_11_full_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator3' */
  model1_11_full_X.Integrator3_CSTATE = model1_11_full_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  model1_11_full_X.Integrator2_CSTATE = model1_11_full_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  model1_11_full_X.Integrator_CSTATE = model1_11_full_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  model1_11_full_X.Integrator1_CSTATE = model1_11_full_P.Integrator1_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative6' */
  model1_11_full_DW.TimeStampA_p = (rtInf);
  model1_11_full_DW.TimeStampB_b = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative7' */
  model1_11_full_DW.TimeStampA_k = (rtInf);
  model1_11_full_DW.TimeStampB_bd = (rtInf);

  /* InitializeConditions for Integrator: '<S3>/Integrator4' */
  model1_11_full_X.Integrator4_CSTATE = model1_11_full_P.Integrator4_IC_k;

  /* InitializeConditions for Derivative: '<Root>/Derivative4' */
  model1_11_full_DW.TimeStampA_l = (rtInf);
  model1_11_full_DW.TimeStampB_bi = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative5' */
  model1_11_full_DW.TimeStampA_kh = (rtInf);
  model1_11_full_DW.TimeStampB_g = (rtInf);

  /* InitializeConditions for Integrator: '<S5>/Integrator2' */
  model1_11_full_X.Integrator2_CSTATE_i = model1_11_full_P.Integrator2_IC_e;

  /* InitializeConditions for Integrator: '<S6>/Integrator2' */
  model1_11_full_X.Integrator2_CSTATE_o = model1_11_full_P.Integrator2_IC_m;

  /* InitializeConditions for Integrator: '<S3>/Integrator5' */
  model1_11_full_X.Integrator5_CSTATE = model1_11_full_P.Integrator5_IC_i;

  /* InitializeConditions for Memory: '<S3>/Memory3' */
  model1_11_full_DW.Memory3_PreviousInput =
    model1_11_full_P.Memory3_InitialCondition;

  /* InitializeConditions for Memory: '<S4>/Memory2' */
  model1_11_full_DW.Memory2_PreviousInput =
    model1_11_full_P.Memory2_InitialCondition;

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[1] = { 2 };

    real_T rootPeriodicContStateRanges[2] = { -3.1415926535897931,
      3.1415926535897931 };

    (void) memcpy((void*)model1_11_full_PeriodicIndX,
                  rootPeriodicContStateIndices,
                  1*sizeof(int_T));
    (void) memcpy((void*)model1_11_full_PeriodicRngX,
                  rootPeriodicContStateRanges,
                  2*sizeof(real_T));
  }
}

/* Model terminate function */
void model1_11_full_terminate(void)
{
  /* (no terminate code required) */
}
