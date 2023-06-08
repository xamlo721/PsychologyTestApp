#ifndef LOGICCONSTANTS_H
#define LOGICCONSTANTS_H

// Будем описывать тут константы, которые по хорошему должны быть загружены из xml

#include <stdexcept>
#include <exception>

#include <QString>



class LogicConstants {

    private:

    public:
    int torsonRawTable[196] = {};

        enum EnumTorsonResult : int {

            VeryLow,

            Low,

            Medium,

            High,

            VeryHigh

        };

        LogicConstants() {


        {
            this->torsonRawTable[0] = 0;
            this->torsonRawTable[1] = 0;
            this->torsonRawTable[2] = 27;
            this->torsonRawTable[3] = 27;
            this->torsonRawTable[4] = 28;
            this->torsonRawTable[5] = 28;
            this->torsonRawTable[6] = 29;
            this->torsonRawTable[7] = 29;
            this->torsonRawTable[8] = 30;
            this->torsonRawTable[9] = 30;

            this->torsonRawTable[10] = 30;
            this->torsonRawTable[11] = 31;
            this->torsonRawTable[12] = 31;
            this->torsonRawTable[13] = 32;
            this->torsonRawTable[14] = 32;
            this->torsonRawTable[15] = 33;
            this->torsonRawTable[16] = 33;
            this->torsonRawTable[17] = 34;
            this->torsonRawTable[18] = 34;
            this->torsonRawTable[19] = 34;

            this->torsonRawTable[20] = 35;
            this->torsonRawTable[21] = 35;
            this->torsonRawTable[22] = 36;
            this->torsonRawTable[23] = 36;
            this->torsonRawTable[24] = 36;
            this->torsonRawTable[25] = 37;
            this->torsonRawTable[26] = 37;
            this->torsonRawTable[27] = 38;
            this->torsonRawTable[28] = 38;
            this->torsonRawTable[29] = 38;

            this->torsonRawTable[30] = 38;
            this->torsonRawTable[31] = 39;
            this->torsonRawTable[32] = 39;
            this->torsonRawTable[33] = 39;
            this->torsonRawTable[34] = 40;
            this->torsonRawTable[35] = 40;
            this->torsonRawTable[36] = 40;
            this->torsonRawTable[37] = 41;
            this->torsonRawTable[38] = 41;
            this->torsonRawTable[39] = 42;

            this->torsonRawTable[40] = 42;
            this->torsonRawTable[41] = 42;
            this->torsonRawTable[42] = 43;
            this->torsonRawTable[43] = 43;
            this->torsonRawTable[44] = 43;
            this->torsonRawTable[45] = 44;
            this->torsonRawTable[46] = 44;
            this->torsonRawTable[47] = 44;
            this->torsonRawTable[48] = 45;
            this->torsonRawTable[49] = 45;

            this->torsonRawTable[50] = 45;
            this->torsonRawTable[51] = 46;
            this->torsonRawTable[52] = 46;
            this->torsonRawTable[53] = 46;
            this->torsonRawTable[54] = 47;
            this->torsonRawTable[55] = 47;
            this->torsonRawTable[56] = 48;
            this->torsonRawTable[57] = 48;
            this->torsonRawTable[58] = 48;
            this->torsonRawTable[59] = 49;

            this->torsonRawTable[60] = 49;
            this->torsonRawTable[61] = 49;
            this->torsonRawTable[62] = 50;
            this->torsonRawTable[63] = 50;
            this->torsonRawTable[64] = 50;
            this->torsonRawTable[65] = 51;
            this->torsonRawTable[66] = 51;
            this->torsonRawTable[67] = 51;
            this->torsonRawTable[68] = 52;
            this->torsonRawTable[69] = 52;

            this->torsonRawTable[70] = 52;
            this->torsonRawTable[71] = 53;
            this->torsonRawTable[72] = 53;
            this->torsonRawTable[73] = 53;
            this->torsonRawTable[74] = 54;
            this->torsonRawTable[75] = 54;
            this->torsonRawTable[76] = 54;
            this->torsonRawTable[77] = 55;
            this->torsonRawTable[78] = 55;
            this->torsonRawTable[79] = 55;

            this->torsonRawTable[80] = 56;
            this->torsonRawTable[81] = 56;
            this->torsonRawTable[82] = 57;
            this->torsonRawTable[83] = 57;
            this->torsonRawTable[84] = 57;
            this->torsonRawTable[85] = 57;
            this->torsonRawTable[86] = 58;
            this->torsonRawTable[87] = 58;
            this->torsonRawTable[88] = 59;
            this->torsonRawTable[89] = 59;

            this->torsonRawTable[90] = 59;
            this->torsonRawTable[91] = 60;
            this->torsonRawTable[92] = 60;
            this->torsonRawTable[93] = 60;
            this->torsonRawTable[94] = 60;
            this->torsonRawTable[95] = 61;
            this->torsonRawTable[96] = 61;
            this->torsonRawTable[97] = 61;
            this->torsonRawTable[98] = 62;
            this->torsonRawTable[99] = 62;

            this->torsonRawTable[100] = 62;
            this->torsonRawTable[101] = 63;
            this->torsonRawTable[102] = 63;
            this->torsonRawTable[103] = 63;
            this->torsonRawTable[104] = 64;
            this->torsonRawTable[105] = 64;
            this->torsonRawTable[106] = 64;
            this->torsonRawTable[107] = 65;
            this->torsonRawTable[108] = 65;
            this->torsonRawTable[109] = 66;
            //В какой-то момент, мне стало казать, что главным пациентом этого теста являюсь я. А мир вокруг симулятор тестов

            this->torsonRawTable[110] = 66;
            this->torsonRawTable[111] = 66;
            this->torsonRawTable[112] = 67;
            this->torsonRawTable[113] = 67;
            this->torsonRawTable[114] = 67;
            this->torsonRawTable[115] = 68;
            this->torsonRawTable[116] = 68;
            this->torsonRawTable[117] = 68;
            this->torsonRawTable[118] = 69;
            this->torsonRawTable[119] = 69;

            this->torsonRawTable[120] = 70;
            this->torsonRawTable[121] = 70;
            this->torsonRawTable[122] = 71;
            this->torsonRawTable[123] = 71;
            this->torsonRawTable[124] = 71;
            this->torsonRawTable[125] = 72;
            this->torsonRawTable[126] = 72;
            this->torsonRawTable[127] = 73;
            this->torsonRawTable[128] = 73;
            this->torsonRawTable[129] = 73;

            this->torsonRawTable[130] = 74;//Мне уже просто интересно, а как эти баллы считали?
            this->torsonRawTable[131] = 74;
            this->torsonRawTable[132] = 74;
            this->torsonRawTable[133] = 74;
            this->torsonRawTable[134] = 75;
            this->torsonRawTable[135] = 75;
            this->torsonRawTable[136] = 76;
            this->torsonRawTable[137] = 76;
            this->torsonRawTable[138] = 76;
            this->torsonRawTable[139] = 76;
            //Что такое безумие?
            this->torsonRawTable[140] = 76;
            this->torsonRawTable[141] = 77;
            this->torsonRawTable[142] = 77;
            this->torsonRawTable[143] = 78;
            this->torsonRawTable[144] = 78;
            this->torsonRawTable[145] = 78;
            this->torsonRawTable[146] = 79;
            this->torsonRawTable[147] = 79;
            this->torsonRawTable[148] = 80;
            this->torsonRawTable[149] = 80;

            this->torsonRawTable[150] = 80;
            this->torsonRawTable[151] = 80;
            this->torsonRawTable[152] = 80;
            this->torsonRawTable[153] = 80;
            this->torsonRawTable[154] = 80;
            this->torsonRawTable[155] = 81;
            this->torsonRawTable[156] = 82;
            this->torsonRawTable[157] = 82;
            this->torsonRawTable[158] = 82;
            this->torsonRawTable[159] = 83;

            this->torsonRawTable[160] = 83;
            this->torsonRawTable[161] = 83;
            this->torsonRawTable[162] = 84;
            this->torsonRawTable[163] = 84;
            this->torsonRawTable[164] = 84;
            this->torsonRawTable[165] = 84;
            this->torsonRawTable[166] = 84;
            this->torsonRawTable[167] = 84;
            this->torsonRawTable[168] = 84;
            this->torsonRawTable[169] = 84;

            this->torsonRawTable[170] = 84;
            this->torsonRawTable[171] = 84;
            this->torsonRawTable[172] = 84;
            this->torsonRawTable[173] = 84;
            this->torsonRawTable[174] = 84;
            this->torsonRawTable[175] = 86;
            this->torsonRawTable[176] = 86;
            this->torsonRawTable[177] = 86;
            this->torsonRawTable[178] = 86;
            this->torsonRawTable[179] = 86;

            this->torsonRawTable[180] = 86;
            this->torsonRawTable[181] = 87;
            this->torsonRawTable[182] = 87;
            this->torsonRawTable[183] = 87;
            this->torsonRawTable[184] = 87;
            this->torsonRawTable[185] = 87;
            this->torsonRawTable[186] = 87;
            this->torsonRawTable[187] = 87;
            this->torsonRawTable[188] = 87;
            this->torsonRawTable[189] = 87;
            //Мне плохо..........................
            this->torsonRawTable[190] = 87;
            this->torsonRawTable[191] = 87;
            this->torsonRawTable[192] = 87;
            this->torsonRawTable[193] = 87;
            this->torsonRawTable[194] = 87;
            this->torsonRawTable[195] = 87;
            }

        }

        int convertTorsonRawState(int raw) {
            if (raw < 3 || raw > 195) {
                return 0;
            }
            return torsonRawTable[raw];
        }

        EnumTorsonResult getTorsonResult(int converted) {
            if (converted < 27) {
                throw std::runtime_error(QString("[ApplicationLogic] Error loading Test!").toLocal8Bit().constData());
            } else if (converted < 30) {
                return EnumTorsonResult::VeryLow;
            } else if (converted < 40) {
                return EnumTorsonResult::Low;
            } else if (converted < 61) {
                return EnumTorsonResult::Medium;
            } else if (converted < 71) {
                return EnumTorsonResult::High;
            } else if (converted < 81) {
                return EnumTorsonResult::VeryHigh;
            } else {
                throw std::runtime_error(QString("[ApplicationLogic] Error loading Test!").toLocal8Bit().constData());
            }
        }
};

#endif // LOGICCONSTANTS_H
