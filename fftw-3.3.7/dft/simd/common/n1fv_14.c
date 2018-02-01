/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Oct 29 08:16:13 EDT 2017 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 14 -name n1fv_14 -include dft/simd/n1f.h */

/*
 * This function contains 74 FP additions, 48 FP multiplications,
 * (or, 32 additions, 6 multiplications, 42 fused multiply/add),
 * 51 stack variables, 6 constants, and 28 memory accesses
 */
#include "dft/simd/n1f.h"

static void n1fv_14(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP801937735, +0.801937735804838252472204639014890102331838324);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DVK(KP554958132, +0.554958132087371191422194871006410481067288862);
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP692021471, +0.692021471630095869627814897002069140197260599);
     DVK(KP356895867, +0.356895867892209443894399510021300583399127187);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(28, is), MAKE_VOLATILE_STRIDE(28, os)) {
	       V T3, TH, Ts, TV, TW, Tt, Tu, TU, Ta, To, Th, Tp, TC, Tx, TK;
	       V TQ, TN, TR, T14, TZ, T1, T2;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
	       T3 = VSUB(T1, T2);
	       TH = VADD(T1, T2);
	       {
		    V T6, TI, T9, TJ, Tn, TP, Tk, TO, Tg, TM, Td, TL;
		    {
			 V T4, T5, Ti, Tj;
			 T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 TI = VADD(T4, T5);
			 {
			      V T7, T8, Tl, Tm;
			      T7 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			      T8 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			      T9 = VSUB(T7, T8);
			      TJ = VADD(T7, T8);
			      Tl = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			      Tm = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			      Tn = VSUB(Tl, Tm);
			      TP = VADD(Tl, Tm);
			 }
			 Ti = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 Tj = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 Tk = VSUB(Ti, Tj);
			 TO = VADD(Ti, Tj);
			 {
			      V Te, Tf, Tb, Tc;
			      Te = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
			      Tf = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			      Tg = VSUB(Te, Tf);
			      TM = VADD(Te, Tf);
			      Tb = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			      Tc = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			      Td = VSUB(Tb, Tc);
			      TL = VADD(Tb, Tc);
			 }
		    }
		    Ts = VSUB(T9, T6);
		    TV = VSUB(TL, TM);
		    TW = VSUB(TJ, TI);
		    Tt = VSUB(Tn, Tk);
		    Tu = VSUB(Tg, Td);
		    TU = VSUB(TO, TP);
		    Ta = VADD(T6, T9);
		    To = VADD(Tk, Tn);
		    Th = VADD(Td, Tg);
		    Tp = VFNMS(LDK(KP356895867), Ta, To);
		    TC = VFNMS(LDK(KP356895867), To, Th);
		    Tx = VFNMS(LDK(KP356895867), Th, Ta);
		    TK = VADD(TI, TJ);
		    TQ = VADD(TO, TP);
		    TN = VADD(TL, TM);
		    TR = VFNMS(LDK(KP356895867), TQ, TN);
		    T14 = VFNMS(LDK(KP356895867), TN, TK);
		    TZ = VFNMS(LDK(KP356895867), TK, TQ);
	       }
	       ST(&(xo[WS(os, 7)]), VADD(T3, VADD(Ta, VADD(Th, To))), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[0]), VADD(TH, VADD(TK, VADD(TN, TQ))), ovs, &(xo[0]));
	       {
		    V Tr, Tw, Tq, Tv;
		    Tq = VFNMS(LDK(KP692021471), Tp, Th);
		    Tr = VFNMS(LDK(KP900968867), Tq, T3);
		    Tv = VFMA(LDK(KP554958132), Tu, Tt);
		    Tw = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Tv, Ts));
		    ST(&(xo[WS(os, 5)]), VFNMSI(Tw, Tr), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 9)]), VFMAI(Tw, Tr), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V T16, T18, T15, T17;
		    T15 = VFNMS(LDK(KP692021471), T14, TQ);
		    T16 = VFNMS(LDK(KP900968867), T15, TH);
		    T17 = VFNMS(LDK(KP554958132), TU, TW);
		    T18 = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), T17, TV));
		    ST(&(xo[WS(os, 6)]), VFMAI(T18, T16), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 8)]), VFNMSI(T18, T16), ovs, &(xo[0]));
	       }
	       {
		    V Tz, TB, Ty, TA;
		    Ty = VFNMS(LDK(KP692021471), Tx, To);
		    Tz = VFNMS(LDK(KP900968867), Ty, T3);
		    TA = VFMA(LDK(KP554958132), Tt, Ts);
		    TB = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), TA, Tu));
		    ST(&(xo[WS(os, 13)]), VFNMSI(TB, Tz), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 1)]), VFMAI(TB, Tz), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V TT, TY, TS, TX;
		    TS = VFNMS(LDK(KP692021471), TR, TK);
		    TT = VFNMS(LDK(KP900968867), TS, TH);
		    TX = VFMA(LDK(KP554958132), TW, TV);
		    TY = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), TX, TU));
		    ST(&(xo[WS(os, 4)]), VFMAI(TY, TT), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 10)]), VFNMSI(TY, TT), ovs, &(xo[0]));
	       }
	       {
		    V T11, T13, T10, T12;
		    T10 = VFNMS(LDK(KP692021471), TZ, TN);
		    T11 = VFNMS(LDK(KP900968867), T10, TH);
		    T12 = VFMA(LDK(KP554958132), TV, TU);
		    T13 = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), T12, TW));
		    ST(&(xo[WS(os, 2)]), VFMAI(T13, T11), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 12)]), VFNMSI(T13, T11), ovs, &(xo[0]));
	       }
	       {
		    V TE, TG, TD, TF;
		    TD = VFNMS(LDK(KP692021471), TC, Ta);
		    TE = VFNMS(LDK(KP900968867), TD, T3);
		    TF = VFNMS(LDK(KP554958132), Ts, Tu);
		    TG = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), TF, Tt));
		    ST(&(xo[WS(os, 11)]), VFNMSI(TG, TE), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 3)]), VFMAI(TG, TE), ovs, &(xo[WS(os, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 14, XSIMD_STRING("n1fv_14"), {32, 6, 42, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_14) (planner *p) {
     X(kdft_register) (p, n1fv_14, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 14 -name n1fv_14 -include dft/simd/n1f.h */

/*
 * This function contains 74 FP additions, 36 FP multiplications,
 * (or, 50 additions, 12 multiplications, 24 fused multiply/add),
 * 33 stack variables, 6 constants, and 28 memory accesses
 */
#include "dft/simd/n1f.h"

static void n1fv_14(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP222520933, +0.222520933956314404288902564496794759466355569);
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP623489801, +0.623489801858733530525004884004239810632274731);
     DVK(KP433883739, +0.433883739117558120475768332848358754609990728);
     DVK(KP781831482, +0.781831482468029808708444526674057750232334519);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(28, is), MAKE_VOLATILE_STRIDE(28, os)) {
	       V T3, Ty, To, TK, Tr, TE, Ta, TJ, Tq, TB, Th, TL, Ts, TH, T1;
	       V T2;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
	       T3 = VSUB(T1, T2);
	       Ty = VADD(T1, T2);
	       {
		    V Tk, TC, Tn, TD;
		    {
			 V Ti, Tj, Tl, Tm;
			 Ti = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 Tj = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 Tk = VSUB(Ti, Tj);
			 TC = VADD(Ti, Tj);
			 Tl = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 Tm = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tn = VSUB(Tl, Tm);
			 TD = VADD(Tl, Tm);
		    }
		    To = VADD(Tk, Tn);
		    TK = VSUB(TC, TD);
		    Tr = VSUB(Tn, Tk);
		    TE = VADD(TC, TD);
	       }
	       {
		    V T6, Tz, T9, TA;
		    {
			 V T4, T5, T7, T8;
			 T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 Tz = VADD(T4, T5);
			 T7 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 T9 = VSUB(T7, T8);
			 TA = VADD(T7, T8);
		    }
		    Ta = VADD(T6, T9);
		    TJ = VSUB(TA, Tz);
		    Tq = VSUB(T9, T6);
		    TB = VADD(Tz, TA);
	       }
	       {
		    V Td, TF, Tg, TG;
		    {
			 V Tb, Tc, Te, Tf;
			 Tb = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 Td = VSUB(Tb, Tc);
			 TF = VADD(Tb, Tc);
			 Te = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
			 Tf = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 Tg = VSUB(Te, Tf);
			 TG = VADD(Te, Tf);
		    }
		    Th = VADD(Td, Tg);
		    TL = VSUB(TF, TG);
		    Ts = VSUB(Tg, Td);
		    TH = VADD(TF, TG);
	       }
	       ST(&(xo[WS(os, 7)]), VADD(T3, VADD(Ta, VADD(Th, To))), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[0]), VADD(Ty, VADD(TB, VADD(TH, TE))), ovs, &(xo[0]));
	       {
		    V Tt, Tp, TP, TQ;
		    Tt = VBYI(VFNMS(LDK(KP781831482), Tr, VFNMS(LDK(KP433883739), Ts, VMUL(LDK(KP974927912), Tq))));
		    Tp = VFMA(LDK(KP623489801), To, VFNMS(LDK(KP900968867), Th, VFNMS(LDK(KP222520933), Ta, T3)));
		    ST(&(xo[WS(os, 5)]), VSUB(Tp, Tt), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 9)]), VADD(Tp, Tt), ovs, &(xo[WS(os, 1)]));
		    TP = VBYI(VFMA(LDK(KP974927912), TJ, VFMA(LDK(KP433883739), TL, VMUL(LDK(KP781831482), TK))));
		    TQ = VFMA(LDK(KP623489801), TE, VFNMS(LDK(KP900968867), TH, VFNMS(LDK(KP222520933), TB, Ty)));
		    ST(&(xo[WS(os, 2)]), VADD(TP, TQ), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 12)]), VSUB(TQ, TP), ovs, &(xo[0]));
	       }
	       {
		    V Tv, Tu, TM, TI;
		    Tv = VBYI(VFMA(LDK(KP781831482), Tq, VFMA(LDK(KP974927912), Ts, VMUL(LDK(KP433883739), Tr))));
		    Tu = VFMA(LDK(KP623489801), Ta, VFNMS(LDK(KP900968867), To, VFNMS(LDK(KP222520933), Th, T3)));
		    ST(&(xo[WS(os, 13)]), VSUB(Tu, Tv), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 1)]), VADD(Tu, Tv), ovs, &(xo[WS(os, 1)]));
		    TM = VBYI(VFNMS(LDK(KP433883739), TK, VFNMS(LDK(KP974927912), TL, VMUL(LDK(KP781831482), TJ))));
		    TI = VFMA(LDK(KP623489801), TB, VFNMS(LDK(KP900968867), TE, VFNMS(LDK(KP222520933), TH, Ty)));
		    ST(&(xo[WS(os, 6)]), VSUB(TI, TM), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 8)]), VADD(TM, TI), ovs, &(xo[0]));
	       }
	       {
		    V TO, TN, Tx, Tw;
		    TO = VBYI(VFMA(LDK(KP433883739), TJ, VFNMS(LDK(KP974927912), TK, VMUL(LDK(KP781831482), TL))));
		    TN = VFMA(LDK(KP623489801), TH, VFNMS(LDK(KP222520933), TE, VFNMS(LDK(KP900968867), TB, Ty)));
		    ST(&(xo[WS(os, 4)]), VSUB(TN, TO), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 10)]), VADD(TO, TN), ovs, &(xo[0]));
		    Tx = VBYI(VFMA(LDK(KP433883739), Tq, VFNMS(LDK(KP781831482), Ts, VMUL(LDK(KP974927912), Tr))));
		    Tw = VFMA(LDK(KP623489801), Th, VFNMS(LDK(KP222520933), To, VFNMS(LDK(KP900968867), Ta, T3)));
		    ST(&(xo[WS(os, 11)]), VSUB(Tw, Tx), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 3)]), VADD(Tw, Tx), ovs, &(xo[WS(os, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 14, XSIMD_STRING("n1fv_14"), {50, 12, 24, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_14) (planner *p) {
     X(kdft_register) (p, n1fv_14, &desc);
}

#endif
