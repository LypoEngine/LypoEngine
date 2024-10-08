//
// Created by guill on 2024-09-27.
//

#ifndef PROFILER_CONFIGURATIONS_H
#define PROFILER_CONFIGURATIONS_H

namespace hive
{
    using color_t = uint32_t;

    namespace colors
    {

    constexpr color_t Red50   = 0xffffebee;
    constexpr color_t Red100  = 0xffffcdd2;
    constexpr color_t Red200  = 0xffef9a9a;
    constexpr color_t Red300  = 0xffe57373;
    constexpr color_t Red400  = 0xffef5350;
    constexpr color_t Red500  = 0xfff44336;
    constexpr color_t Red600  = 0xffe53935;
    constexpr color_t Red700  = 0xffd32f2f;
    constexpr color_t Red800  = 0xffc62828;
    constexpr color_t Red900  = 0xffb71c1c;
    constexpr color_t RedA100 = 0xffff8a80;
    constexpr color_t RedA200 = 0xffff5252;
    constexpr color_t RedA400 = 0xffff1744;
    constexpr color_t RedA700 = 0xffd50000;

    constexpr color_t Pink50   = 0xfffce4ec;
    constexpr color_t Pink100  = 0xfff8bbd0;
    constexpr color_t Pink200  = 0xfff48fb1;
    constexpr color_t Pink300  = 0xfff06292;
    constexpr color_t Pink400  = 0xffec407a;
    constexpr color_t Pink500  = 0xffe91e63;
    constexpr color_t Pink600  = 0xffd81b60;
    constexpr color_t Pink700  = 0xffc2185b;
    constexpr color_t Pink800  = 0xffad1457;
    constexpr color_t Pink900  = 0xff880e4f;
    constexpr color_t PinkA100 = 0xffff80ab;
    constexpr color_t PinkA200 = 0xffff4081;
    constexpr color_t PinkA400 = 0xfff50057;
    constexpr color_t PinkA700 = 0xffc51162;

    constexpr color_t Purple50   = 0xfff3e5f5;
    constexpr color_t Purple100  = 0xffe1bee7;
    constexpr color_t Purple200  = 0xffce93d8;
    constexpr color_t Purple300  = 0xffba68c8;
    constexpr color_t Purple400  = 0xffab47bc;
    constexpr color_t Purple500  = 0xff9c27b0;
    constexpr color_t Purple600  = 0xff8e24aa;
    constexpr color_t Purple700  = 0xff7b1fa2;
    constexpr color_t Purple800  = 0xff6a1b9a;
    constexpr color_t Purple900  = 0xff4a148c;
    constexpr color_t PurpleA100 = 0xffea80fc;
    constexpr color_t PurpleA200 = 0xffe040fb;
    constexpr color_t PurpleA400 = 0xffd500f9;
    constexpr color_t PurpleA700 = 0xffaa00ff;

    constexpr color_t DeepPurple50   = 0xffede7f6;
    constexpr color_t DeepPurple100  = 0xffd1c4e9;
    constexpr color_t DeepPurple200  = 0xffb39ddb;
    constexpr color_t DeepPurple300  = 0xff9575cd;
    constexpr color_t DeepPurple400  = 0xff7e57c2;
    constexpr color_t DeepPurple500  = 0xff673ab7;
    constexpr color_t DeepPurple600  = 0xff5e35b1;
    constexpr color_t DeepPurple700  = 0xff512da8;
    constexpr color_t DeepPurple800  = 0xff4527a0;
    constexpr color_t DeepPurple900  = 0xff311b92;
    constexpr color_t DeepPurpleA100 = 0xffb388ff;
    constexpr color_t DeepPurpleA200 = 0xff7c4dff;
    constexpr color_t DeepPurpleA400 = 0xff651fff;
    constexpr color_t DeepPurpleA700 = 0xff6200ea;

    constexpr color_t Indigo50   = 0xffe8eaf6;
    constexpr color_t Indigo100  = 0xffc5cae9;
    constexpr color_t Indigo200  = 0xff9fa8da;
    constexpr color_t Indigo300  = 0xff7986cb;
    constexpr color_t Indigo400  = 0xff5c6bc0;
    constexpr color_t Indigo500  = 0xff3f51b5;
    constexpr color_t Indigo600  = 0xff3949ab;
    constexpr color_t Indigo700  = 0xff303f9f;
    constexpr color_t Indigo800  = 0xff283593;
    constexpr color_t Indigo900  = 0xff1a237e;
    constexpr color_t IndigoA100 = 0xff8c9eff;
    constexpr color_t IndigoA200 = 0xff536dfe;
    constexpr color_t IndigoA400 = 0xff3d5afe;
    constexpr color_t IndigoA700 = 0xff304ffe;

    constexpr color_t Blue50   = 0xffe3f2fd;
    constexpr color_t Blue100  = 0xffbbdefb;
    constexpr color_t Blue200  = 0xff90caf9;
    constexpr color_t Blue300  = 0xff64b5f6;
    constexpr color_t Blue400  = 0xff42a5f5;
    constexpr color_t Blue500  = 0xff2196f3;
    constexpr color_t Blue600  = 0xff1e88e5;
    constexpr color_t Blue700  = 0xff1976d2;
    constexpr color_t Blue800  = 0xff1565c0;
    constexpr color_t Blue900  = 0xff0d47a1;
    constexpr color_t BlueA100 = 0xff82b1ff;
    constexpr color_t BlueA200 = 0xff448aff;
    constexpr color_t BlueA400 = 0xff2979ff;
    constexpr color_t BlueA700 = 0xff2962ff;

    constexpr color_t LightBlue50   = 0xffe1f5fe;
    constexpr color_t LightBlue100  = 0xffb3e5fc;
    constexpr color_t LightBlue200  = 0xff81d4fa;
    constexpr color_t LightBlue300  = 0xff4fc3f7;
    constexpr color_t LightBlue400  = 0xff29b6f6;
    constexpr color_t LightBlue500  = 0xff03a9f4;
    constexpr color_t LightBlue600  = 0xff039be5;
    constexpr color_t LightBlue700  = 0xff0288d1;
    constexpr color_t LightBlue800  = 0xff0277bd;
    constexpr color_t LightBlue900  = 0xff01579b;
    constexpr color_t LightBlueA100 = 0xff80d8ff;
    constexpr color_t LightBlueA200 = 0xff40c4ff;
    constexpr color_t LightBlueA400 = 0xff00b0ff;
    constexpr color_t LightBlueA700 = 0xff0091ea;

    constexpr color_t Cyan50   = 0xffe0f7fa;
    constexpr color_t Cyan100  = 0xffb2ebf2;
    constexpr color_t Cyan200  = 0xff80deea;
    constexpr color_t Cyan300  = 0xff4dd0e1;
    constexpr color_t Cyan400  = 0xff26c6da;
    constexpr color_t Cyan500  = 0xff00bcd4;
    constexpr color_t Cyan600  = 0xff00acc1;
    constexpr color_t Cyan700  = 0xff0097a7;
    constexpr color_t Cyan800  = 0xff00838f;
    constexpr color_t Cyan900  = 0xff006064;
    constexpr color_t CyanA100 = 0xff84ffff;
    constexpr color_t CyanA200 = 0xff18ffff;
    constexpr color_t CyanA400 = 0xff00e5ff;
    constexpr color_t CyanA700 = 0xff00b8d4;

    constexpr color_t Teal50   = 0xffe0f2f1;
    constexpr color_t Teal100  = 0xffb2dfdb;
    constexpr color_t Teal200  = 0xff80cbc4;
    constexpr color_t Teal300  = 0xff4db6ac;
    constexpr color_t Teal400  = 0xff26a69a;
    constexpr color_t Teal500  = 0xff009688;
    constexpr color_t Teal600  = 0xff00897b;
    constexpr color_t Teal700  = 0xff00796b;
    constexpr color_t Teal800  = 0xff00695c;
    constexpr color_t Teal900  = 0xff004d40;
    constexpr color_t TealA100 = 0xffa7ffeb;
    constexpr color_t TealA200 = 0xff64ffda;
    constexpr color_t TealA400 = 0xff1de9b6;
    constexpr color_t TealA700 = 0xff00bfa5;

    constexpr color_t Green50   = 0xffe8f5e9;
    constexpr color_t Green100  = 0xffc8e6c9;
    constexpr color_t Green200  = 0xffa5d6a7;
    constexpr color_t Green300  = 0xff81c784;
    constexpr color_t Green400  = 0xff66bb6a;
    constexpr color_t Green500  = 0xff4caf50;
    constexpr color_t Green600  = 0xff43a047;
    constexpr color_t Green700  = 0xff388e3c;
    constexpr color_t Green800  = 0xff2e7d32;
    constexpr color_t Green900  = 0xff1b5e20;
    constexpr color_t GreenA100 = 0xffb9f6ca;
    constexpr color_t GreenA200 = 0xff69f0ae;
    constexpr color_t GreenA400 = 0xff00e676;
    constexpr color_t GreenA700 = 0xff00c853;

    constexpr color_t LightGreen50   = 0xfff1f8e9;
    constexpr color_t LightGreen100  = 0xffdcedc8;
    constexpr color_t LightGreen200  = 0xffc5e1a5;
    constexpr color_t LightGreen300  = 0xffaed581;
    constexpr color_t LightGreen400  = 0xff9ccc65;
    constexpr color_t LightGreen500  = 0xff8bc34a;
    constexpr color_t LightGreen600  = 0xff7cb342;
    constexpr color_t LightGreen700  = 0xff689f38;
    constexpr color_t LightGreen800  = 0xff558b2f;
    constexpr color_t LightGreen900  = 0xff33691e;
    constexpr color_t LightGreenA100 = 0xffccff90;
    constexpr color_t LightGreenA200 = 0xffb2ff59;
    constexpr color_t LightGreenA400 = 0xff76ff03;
    constexpr color_t LightGreenA700 = 0xff64dd17;

    constexpr color_t Lime50   = 0xfff9ebe7;
    constexpr color_t Lime100  = 0xfff0f4c3;
    constexpr color_t Lime200  = 0xffe6ee9c;
    constexpr color_t Lime300  = 0xffdce775;
    constexpr color_t Lime400  = 0xffd4e157;
    constexpr color_t Lime500  = 0xffcddc39;
    constexpr color_t Lime600  = 0xffc0ca33;
    constexpr color_t Lime700  = 0xffafb42b;
    constexpr color_t Lime800  = 0xff9e9d24;
    constexpr color_t Lime900  = 0xff827717;
    constexpr color_t LimeA100 = 0xfff4ff81;
    constexpr color_t LimeA200 = 0xffeeff41;
    constexpr color_t LimeA400 = 0xffc6ff00;
    constexpr color_t LimeA700 = 0xffaeea00;

    constexpr color_t Yellow50   = 0xfffffde7;
    constexpr color_t Yellow100  = 0xfffff9c4;
    constexpr color_t Yellow200  = 0xfffff59d;
    constexpr color_t Yellow300  = 0xfffff176;
    constexpr color_t Yellow400  = 0xffffee58;
    constexpr color_t Yellow500  = 0xffffeb3b;
    constexpr color_t Yellow600  = 0xfffdd835;
    constexpr color_t Yellow700  = 0xfffbc02d;
    constexpr color_t Yellow800  = 0xfff9a825;
    constexpr color_t Yellow900  = 0xfff57f17;
    constexpr color_t YellowA100 = 0xffffff8d;
    constexpr color_t YellowA200 = 0xffffff00;
    constexpr color_t YellowA400 = 0xffffea00;
    constexpr color_t YellowA700 = 0xffffd600;

    constexpr color_t Amber50   = 0xfffff8e1;
    constexpr color_t Amber100  = 0xffffecb3;
    constexpr color_t Amber200  = 0xffffe082;
    constexpr color_t Amber300  = 0xffffd54f;
    constexpr color_t Amber400  = 0xffffca28;
    constexpr color_t Amber500  = 0xffffc107;
    constexpr color_t Amber600  = 0xffffb300;
    constexpr color_t Amber700  = 0xffffa000;
    constexpr color_t Amber800  = 0xffff8f00;
    constexpr color_t Amber900  = 0xffff6f00;
    constexpr color_t AmberA100 = 0xffffe57f;
    constexpr color_t AmberA200 = 0xffffd740;
    constexpr color_t AmberA400 = 0xffffc400;
    constexpr color_t AmberA700 = 0xffffab00;

    constexpr color_t Orange50   = 0xfffff3e0;
    constexpr color_t Orange100  = 0xffffe0b2;
    constexpr color_t Orange200  = 0xffffcc80;
    constexpr color_t Orange300  = 0xffffb74d;
    constexpr color_t Orange400  = 0xffffa726;
    constexpr color_t Orange500  = 0xffff9800;
    constexpr color_t Orange600  = 0xfffb8c00;
    constexpr color_t Orange700  = 0xfff57c00;
    constexpr color_t Orange800  = 0xffef6c00;
    constexpr color_t Orange900  = 0xffe65100;
    constexpr color_t OrangeA100 = 0xffffd180;
    constexpr color_t OrangeA200 = 0xffffab40;
    constexpr color_t OrangeA400 = 0xffff9100;
    constexpr color_t OrangeA700 = 0xffff6d00;

    constexpr color_t DeepOrange50   = 0xfffbe9e7;
    constexpr color_t DeepOrange100  = 0xffffccbc;
    constexpr color_t DeepOrange200  = 0xffffab91;
    constexpr color_t DeepOrange300  = 0xffff8a65;
    constexpr color_t DeepOrange400  = 0xffff7043;
    constexpr color_t DeepOrange500  = 0xffff5722;
    constexpr color_t DeepOrange600  = 0xfff4511e;
    constexpr color_t DeepOrange700  = 0xffe64a19;
    constexpr color_t DeepOrange800  = 0xffd84315;
    constexpr color_t DeepOrange900  = 0xffbf360c;
    constexpr color_t DeepOrangeA100 = 0xffff9e80;
    constexpr color_t DeepOrangeA200 = 0xffff6e40;
    constexpr color_t DeepOrangeA400 = 0xffff3d00;
    constexpr color_t DeepOrangeA700 = 0xffdd2c00;

    constexpr color_t Brown50  = 0xffefebe9;
    constexpr color_t Brown100 = 0xffd7ccc8;
    constexpr color_t Brown200 = 0xffbcaaa4;
    constexpr color_t Brown300 = 0xffa1887f;
    constexpr color_t Brown400 = 0xff8d6e63;
    constexpr color_t Brown500 = 0xff795548;
    constexpr color_t Brown600 = 0xff6d4c41;
    constexpr color_t Brown700 = 0xff5d4037;
    constexpr color_t Brown800 = 0xff4e342e;
    constexpr color_t Brown900 = 0xff3e2723;

    constexpr color_t Grey50  = 0xfffafafa;
    constexpr color_t Grey100 = 0xfff5f5f5;
    constexpr color_t Grey200 = 0xffeeeeee;
    constexpr color_t Grey300 = 0xffe0e0e0;
    constexpr color_t Grey400 = 0xffbdbdbd;
    constexpr color_t Grey500 = 0xff9e9e9e;
    constexpr color_t Grey600 = 0xff757575;
    constexpr color_t Grey700 = 0xff616161;
    constexpr color_t Grey800 = 0xff424242;
    constexpr color_t Grey900 = 0xff212121;

    constexpr color_t BlueGrey50  = 0xffeceff1;
    constexpr color_t BlueGrey100 = 0xffcfd8dc;
    constexpr color_t BlueGrey200 = 0xffb0bec5;
    constexpr color_t BlueGrey300 = 0xff90a4ae;
    constexpr color_t BlueGrey400 = 0xff78909c;
    constexpr color_t BlueGrey500 = 0xff607d8b;
    constexpr color_t BlueGrey600 = 0xff546e7a;
    constexpr color_t BlueGrey700 = 0xff455a64;
    constexpr color_t BlueGrey800 = 0xff37474f;
    constexpr color_t BlueGrey900 = 0xff263238;

    constexpr color_t Black  = 0xff000000;
    constexpr color_t White  = 0xffffffff;
    constexpr color_t Null   = 0x00000000;


    constexpr color_t Red         = Red500;
    constexpr color_t DarkRed     = Red900;
    constexpr color_t Coral       = Red200;
    constexpr color_t RichRed     = 0xffff0000;
    constexpr color_t Pink        = Pink500;
    constexpr color_t Rose        = PinkA100;
    constexpr color_t Purple      = Purple500;
    constexpr color_t Magenta     = PurpleA200;
    constexpr color_t DarkMagenta = PurpleA700;
    constexpr color_t DeepPurple  = DeepPurple500;
    constexpr color_t Indigo      = Indigo500;
    constexpr color_t Blue        = Blue500;
    constexpr color_t DarkBlue    = Blue900;
    constexpr color_t RichBlue    = 0xff0000ff;
    constexpr color_t LightBlue   = LightBlue500;
    constexpr color_t SkyBlue     = LightBlueA100;
    constexpr color_t Navy        = LightBlue800;
    constexpr color_t Cyan        = Cyan500;
    constexpr color_t DarkCyan    = Cyan900;
    constexpr color_t Teal        = Teal500;
    constexpr color_t DarkTeal    = Teal900;
    constexpr color_t Green       = Green500;
    constexpr color_t DarkGreen   = Green900;
    constexpr color_t RichGreen   = 0xff00ff00;
    constexpr color_t LightGreen  = LightGreen500;
    constexpr color_t Mint        = LightGreen900;
    constexpr color_t Lime        = Lime500;
    constexpr color_t Olive       = Lime900;
    constexpr color_t Yellow      = Yellow500;
    constexpr color_t RichYellow  = YellowA200;
    constexpr color_t Amber       = Amber500;
    constexpr color_t Gold        = Amber300;
    constexpr color_t PaleGold    = AmberA100;
    constexpr color_t Orange      = Orange500;
    constexpr color_t Skin        = Orange100;
    constexpr color_t DeepOrange  = DeepOrange500;
    constexpr color_t Brick       = DeepOrange900;
    constexpr color_t Brown       = Brown500;
    constexpr color_t DarkBrown   = Brown900;
    constexpr color_t CreamWhite  = Orange50;
    constexpr color_t Wheat       = Amber100;
    constexpr color_t Grey        = Grey500;
    constexpr color_t Dark        = Grey900;
    constexpr color_t Silver      = Grey300;
    constexpr color_t BlueGrey    = BlueGrey500;

    constexpr color_t Default = Wheat;
    }
}

#endif //PROFILER_CONFIGURATIONS_H
