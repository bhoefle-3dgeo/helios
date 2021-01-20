#pragma once

#include <BaseTest.h>
#include <PlaneFitter.h>

namespace HeliosTests{

/**
 * @author Alberto M. Esmoris Pena
 * @version 1.0
 * @brief Test plane fitter operations
 */
class PlaneFitterTest : public BaseTest{
public:
    // ***  CONSTRUCTOR  *** //
    // ********************* //
    /**
     * @brief Plane fitter test constructor
     */
    PlaneFitterTest() : BaseTest("Plane fitter test"){}

    // ***  R U N  *** //
    // *************** //
    /**
     * @see BaseTest::run
     */
    bool run() override;
};


bool PlaneFitterTest::run(){
    double eps = 0.00001; // Decimal precision to validate results

    // Create point cloud as Matrix
    Mat<double> M(3, 64);
    M[0] = -1.0;	                M[1] = -0.5;	                M[2] = -0.2590347239999257;
    M[3] = -0.9523809523809523;		M[4] = -0.35714285714285715;	M[5] = -0.2026780697596828;
    M[6] = -0.9047619047619048;		M[7] = -0.2142857142857143;		M[8] = -0.13139036416092098;
    M[9] = -0.8571428571428572;		M[10] = -0.07142857142857145;   M[11] = -0.04671739828188584;
    M[12] = -0.8095238095238095;	M[13] = 0.0714285714285714;		M[14] = 0.04923262868841574;
    M[15] = -0.7619047619047619;	M[16] = 0.2142857142857142;		M[17] = 0.15385671483694588;
    M[18] = -0.7142857142857143;	M[19] = 0.3571428571428571;		M[20] = 0.26414334627969743;
    M[21] = -0.6666666666666667;	M[22] = 0.5;	                M[23] = 0.37677442328017;
    M[24] = -0.6190476190476191;	M[25] = -0.5;		            M[26] = -0.39045923863043014;
    M[27] = -0.5714285714285714;	M[28] = -0.35714285714285715;	M[29] = -0.2940577704977843;
    M[30] = -0.5238095238095238;	M[31] = -0.2142857142857143;	M[32] = -0.1841374864026063;
    M[33] = -0.4761904761904763;	M[34] = -0.07142857142857145;	M[35] = -0.0634280068591835;
    M[36] = -0.4285714285714286;	M[37] = 0.0714285714285714;		M[38] = 0.06491336523443045;
    M[39] = -0.38095238095238093;   M[40] = 0.2142857142857142;	    M[41] = 0.1974048920650196;
    M[42] = -0.33333333333333337;	M[43] = 0.3571428571428571;	    M[44] = 0.33035582217084464;
    M[45] = -0.2857142857142858;	M[46] = 0.5;	                M[47] = 0.45998990586908256;
    M[48] = -0.23809523809523814;	M[49] = -0.5;		            M[50] = -0.46590045486897663;
    M[51] = -0.19047619047619047;	M[52] = -0.35714285714285715;	M[53] = -0.3432760308561054;
    M[54] = -0.1428571428571429;	M[55] = -0.2142857142857143;	M[56] = -0.21048332823771035;
    M[57] = -0.09523809523809534;	M[58] = -0.07142857142857145;	M[59] = -0.07104442919860406;
    M[60] = -0.04761904761904767;	M[61] = 0.0714285714285714;		M[62] = 0.07128694770133547;
    M[63] = 0.0;	                M[64] = 0.2142857142857142;		M[65] = 0.21264953365318398;
    M[66] = 0.04761904761904745;	M[67] = 0.3571428571428571;		M[68] = 0.3492025124988643;
    M[69] = 0.09523809523809512;	M[70] = 0.5;	                M[71] = 0.4772529160619416;
    M[72] = 0.1428571428571428; 	M[73] = -0.5;		            M[74] = -0.47454175550720074;
    M[75] = 0.19047619047619047;	M[76] = -0.35714285714285715;	M[77] = -0.3432760308561054;
    M[78] = 0.23809523809523814;	M[79] = -0.2142857142857143;	M[80] = -0.20665047328337227;
    M[81] = 0.2857142857142856;		M[82] = -0.07142857142857145;	M[83] = -0.06847463724107901;
    M[84] = 0.33333333333333326;	M[85] = 0.0714285714285714;		M[86] = 0.06743954403249396;
    M[87] = 0.38095238095238093;	M[88] = 0.2142857142857142;		M[89] = 0.1974048920650196;
    M[90] = 0.4285714285714284;		M[91] = 0.3571428571428571;		M[92] = 0.3179812148724512;
    M[93] = 0.47619047619047605;	M[94] = 0.5;	                M[95] = 0.4260883164944473;
    M[96] = 0.5238095238095237;		M[97] = -0.5;		            M[98] = -0.41514416739691623;
    M[99] = 0.5714285714285714;		M[100] = -0.35714285714285715;	M[101] = -0.2940577704977843;
    M[102] = 0.6190476190476191;	M[103] = -0.2142857142857143;	M[104] = -0.17318846894780415;
    M[105] = 0.6666666666666665;	M[106] = -0.07142857142857145;	M[107] = -0.05608708283952904;
    M[108] = 0.7142857142857142;	M[109] = 0.0714285714285714;	M[110] = 0.053922787602960834;
    M[111] = 0.7619047619047619;	M[112] = 0.2142857142857142;	M[113] = 0.15385671483694588;
    M[114] = 0.8095238095238093;	M[115] = 0.3571428571428571;	M[116] = 0.24116837919540182;
    M[117] = 0.857142857142857;		M[118] = 0.5;		            M[119] = 0.3138319895361374;
    M[120] = 0.9047619047619047;	M[121] = -0.5;		            M[122] = -0.29622400304901264;
    M[123] = 0.9523809523809523;	M[124] = -0.35714285714285715;	M[125] = -0.2026780697596828;
    M[126] = 1.0;		            M[127] = -0.2142857142857143;   M[128] = -0.11489503337459996;
    M[129] = 1.0476190476190474;	M[130] = -0.07142857142857145;	M[131] = -0.03565786983731839;
    M[132] = 1.095238095238095;		M[133] = 0.0714285714285714;	M[134] = 0.03267468508185784;
    M[135] = 1.1428571428571428;	M[136] = 0.2142857142857142;	M[137] = 0.08824885627943196;
    M[138] = 1.1904761904761902;	M[139] = 0.3571428571428571;	M[140] = 0.12977728284623108;
    M[141] = 1.2380952380952381;	M[142] = 0.5;		            M[143] = 0.15657903251531574;
    M[144] = 1.2857142857142856;	M[145] = -0.5;		            M[146] = -0.13483180804376932;
    M[147] = 1.333333333333333;		M[148] = -0.35714285714285715;	M[149] = -0.08223877525537533;
    M[150] = 1.380952380952381;		M[151] = -0.2142857142857143;	M[152] = -0.04012816779695861;
    M[153] = 1.4285714285714284;	M[154] = -0.07142857142857145;	M[155] = -0.010116099698218887;
    M[156] = 1.4761904761904763;	M[157] = 0.0714285714285714;	M[158] = 0.006741748745022565;
    M[159] = 1.5238095238095237;	M[160] = 0.2142857142857142;	M[161] = 0.009988045595161994;
    M[162] = 1.5714285714285712;	M[163] = 0.3571428571428571;	M[164] = -0.00022103195565695188;
    M[165] = 1.619047619047619;		M[166] = 0.5;		            M[167] = -0.023123926533824744;
    M[168] = 1.6666666666666665;	M[169] = -0.5;		            M[170] = 0.04589231356389723;
    M[171] = 1.714285714285714;		M[172] = -0.35714285714285715;	M[173] = 0.049991757460274754;
    M[174] = 1.7619047619047619;	M[175] = -0.2142857142857143;	M[176] = 0.04039219768397483;
    M[177] = 1.8095238095238093;	M[178] = -0.07142857142857145;	M[179] = 0.01687609745588645;
    M[180] = 1.8571428571428568;	M[181] = 0.0714285714285714;	M[182] = -0.02015780662482634;
    M[183] = 1.9047619047619047;	M[184] = 0.2142857142857142;	M[185] = -0.06970483195188154;
    M[186] = 1.952380952380952;		M[187] = 0.3571428571428571;	M[188] = -0.13018765561874365;
    M[189] = 2.0;		            M[190] = 0.5;		            M[191] = -0.19951142125004898;

    // Expected results
    std::vector<double> expectedBfpOrthoNormal({
        0.0236664, -0.54025876, 0.84116608
    });

    // Test best fitting plane orthogonal normal computation
    std::vector<double> bfpOrthoNormal =
        PlaneFitter::bestFittingPlaneOrthoNormal(M);
    for(size_t i = 0 ; i < bfpOrthoNormal.size() ; i++){
        double diff = expectedBfpOrthoNormal[i] - bfpOrthoNormal[i];
        if(diff < -eps || diff > eps) return false;
    }

    // Create point cloud 2 as Matrix 2
    Mat<double> M2(3, 16);
    M2[0] = 5.7;        M2[1] = 5.7;        M2[2] = 2.3;
    M2[3] = 5.6;        M2[4] = 5.7;        M2[5] = 2.3;
    M2[6] = 5.6;        M2[7] = 5.6;        M2[8] = 2.3;
    M2[9] = 5.5;        M2[10] = 5.6;       M2[11] = 2.3;
    M2[12] = 5.5;       M2[13] = 5.5;       M2[14] = 2.3;
    M2[15] = 5.4;       M2[16] = 5.5;       M2[17] = 2.3;
    M2[18] = 5.4;       M2[19] = 5.4;       M2[20] = 2.3;
    M2[21] = 5.4;       M2[22] = 5.3;       M2[23] = 2.3;
    M2[24] = 5.3;       M2[25] = 5.3;       M2[26] = 2.3;
    M2[27] = 5.2;       M2[28] = 5.3;       M2[29] = 2.3;
    M2[30] = 5.2;       M2[31] = 5.2;       M2[32] = 2.3;
    M2[33] = 5.2;       M2[34] = 5.1;       M2[35] = 2.3;
    M2[36] = 5.1;       M2[37] = 5.1;       M2[38] = 2.3;
    M2[39] = 5.1;       M2[40] = 5.0;       M2[41] = 2.3;
    M2[42] = 5.0;       M2[43] = 5.0;       M2[44] = 2.3;
    M2[45] = 4.9;       M2[46] = 4.9;       M2[47] = 2.3;

    // Expected results 2
    std::vector<double> expectedBfpOrthoNormal2({
        0.0, 0.0, 1.0
    });
    // Test best fitting plane orthogonal normal computation
    std::vector<double> bfpOrthoNormal2 =
        PlaneFitter::bestFittingPlaneOrthoNormal(M2);
    for(size_t i = 0 ; i < bfpOrthoNormal.size() ; i++){
        double diff = expectedBfpOrthoNormal2[i] - bfpOrthoNormal2[i];
        if(diff < -eps || diff > eps) return false;
    }

    return true;
}

};