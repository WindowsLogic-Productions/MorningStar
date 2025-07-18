using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using static System.Net.Mime.MediaTypeNames;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;
using System.IO;
using System.Data;
using System.Net;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Data.Common;

namespace MorningStar
{ 
    public class stdafx
    {
        // Store member information.
        public ref struct MemberInfo
        {
            IPEndPoint IP_EP;
            String NAME;
            String COMMENT;
            String LOOKING;
            String AVOIDING;
            String REGION;
            String GG;
            UInt16 ID;
            uint TYPE;
            uint NUM_VS;
            uint RESPONSE;
        }
        
        // Backup member information.
        public ref struct MemberInfoBackup
        {
            IPEndPoint IP_EP;
            UInt16 ID;
        }

        
        public class Profile
        {
            public
                static List<String> ProfileList = new List<String>();
            String[] SystemSection = { "System", "State", "Color" };
        }


        // To anyone reading this, know that if you change this once it works, it's on you to fix it, enough sanity was lost here today
        // EDIT - 5 mins later, replace enough with too fkin much
        // KGT2KGAME
        //const uint P1_INPUT = 0x004259C0;
        //const uint P2_INPUT = 0x004259C4;
        //const uint SINGLE_CONTROL_HOOK = 0x00414712;

       // THIS ONE LINE WAS A CODING BREAKTHROUGH, BUT A MENTAL BREAKDOWN
       // Two heads turned out to be better than one, probably saved like 60 seconds at best
       // 61 GOTO 52
       //END
       // Tralalero tralala caused less pain
        static byte[] SINGLE_CONTROL_HOOK_CODE = new byte[] { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };      
        //const uint VS_CONTROL_HOOK = 0x00414748;
        //const byte[] VS_CONTROL_HOOK_CODE[] = { 0x6A, 0x00 };
        //const uint STORY_KEY = 0x00414729;
        //const byte[] STORY_KEY_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_P1_KEY = 0x0041474A;
        //const byte[] VS_P1_KEY_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_P2_KEY = 0x00414764;
        //const byte[] VS_P2_KEY_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint RANDOM_SEED = 0x0041FB1C;
        //const uint RAND_FUNC = 0x00417A22;
        //const byte[] RAND_FUNC_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint HIT_JUDGE = 0x0042470C;
        //const uint HIT_JUDGE_SET = 0x00414C90;
        //const byte[] HIT_JUDGE_SET_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint DEFAULT_ROUND = 0x00430124;
        //const uint ROUND_SET = 0x00414AFC;
        //const byte[] ROUND_SET_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint TEAM_ROUND = 0x00430128;
        //const uint TEAM_ROUND_SET = 0x00414ADB;
        //const byte[] TEAM_ROUND_SET_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint DEFAULT_TIMER = 0x00430114;
        //const uint TIMER_SET = 0x00414A8C;
        //const byte[] TIMER_SET_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_ROUND = 0x0040897F;
        //const byte[] VS_ROUND_CODE[] = { 0xCC };
        //const uint ROUND_ESI = 0x004EDCAC;
        //const uint ROUND_END = 0x00409715;
        //const byte[] ROUND_END_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint P1_HP = 0x004DFC85;
        //const uint P1_MAX_HP = 0x004DFC91;
        //const uint P1_STATE = 0x0047033E;
        //const uint P2_HP = 0x004EDCC4;
        //const uint P2_MAX_HP = 0x004EDCD0;
        //const uint P2_STATE = 0x004704BC;
        //const uint STAGE_SELECT = 0x00408756;
        //const byte[] STAGE_SELECT_CODE = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint FRAME_RATE = 0x00404C37;
        //const byte[] FRAME_RATE_CODE = { 0xCC, 0x90 };
        //const uint BGM_VOLUME = 0x0040347E;
        //const uint SE_VOLUME = 0x0040348C;
        //const uint VOLUME_SET_1 = 0x00403401;
        //const byte[] VOLUME_SET_1_CODE[] = {0x58,0x8B,0x08,0x6A,0x01,0xEB,0x0D,0x58,0x8B,0x08,0x6A,0x00,0xEB,0x06,0x90,0xE9,
        //                          0xEB,0x21,0x01,0x00,0x6A,0x00,0x6A,0x00,0x50,0xFF,0x51,0x30,0x5B,0xC3};
        //const uint VOLUME_SET_2 = 0x0040347B;
        //const byte[] VOLUME_SET_2_CODE[] = {0x50,0x8B,0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x78,0xFF,0xFF,0xFF,0x50,0x8B,
        //                          0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x71,0xFF,0xFF,0xFF};

        // KGT95GAME
        //const uint P1_INPUT_95 = 0x00437750;
        //const uint P2_INPUT_95 = 0x00437754;
        //const uint INPUT_COUNTER_95 = 0x00437700;
        //const uint UNCHECK_JOYSTICK_95 = 0x00402A33;
        //const byte[] UNCHECK_JOYSTICK_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint CONTROL_HOOK1_95 = 0x0040902B;
        //const byte[] CONTROL_HOOK1_95_CODE[] = { 0xE8, 0xB0, 0xFA, 0xFF, 0xFF };
        //const uint CONTROL_HOOK2_95 = 0x00409053;
        //const byte[] CONTROL_HOOK2_95_CODE[] = { 0xE8, 0x88, 0xFA, 0xFF, 0xFF };
        //const uint STORY_P1_KEY_95 = 0x0040901C;
        //const byte[] STORY_P1_KEY_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint STORY_P2_KEY_95 = 0x00409030;
        //const byte[] STORY_P2_KEY_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_P1_KEY_95 = 0x0040904C;
        //const byte[] VS_P1_KEY_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_P2_KEY_95 = 0x00409058;
        //const byte[] VS_P2_KEY_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint RANDOM_SEED_95 = 0x004243FC;
        //const uint RAND_FUNC_95 = 0x0041A864;
        //const byte[] RAND_FUNC_95_CODE = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint HIT_JUDGE_95 = 0x00432740;
        //const uint HIT_JUDGE_SET_95 = 0x004029E9;
        //const byte[] HIT_JUDGE_SET_95_CODE = 0x90, 0x90, 0x90, 0x90, 0x90;
        //const uint DEFAULT_TIMER_95 = 0x00432754;
        //const uint TIMER_SET_95 = 0x00402A68;
        //const byte[] TIMER_SET_95_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint P1_WIN_95 = 0x005E9914;
        //const uint P2_WIN_95 = 0x005E9978;
        //const uint VS_ROUND_95 = 0x00411661;
        //const byte[] VS_ROUND_95_CODE[] = { 0xCC, 0x90 };
        //const uint ROUND_END_95 = 0x00413410;
        //const byte[] ROUND_END_95_CODE[] = { 0xCC, 0x90 };
        //const uint STAGE_SELECT_95 = 0x0041162C;
        //const byte[] STAGE_SELECT_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint FRAME_RATE_95 = 0x00404759;
        //const byte[] FRAME_RATE_95_CODE[] = { 0xCC, 0x90 };
        //const uint BGM_VOLUME_95 = 0x00402042;
        //const uint SE_VOLUME_95 = 0x00402050;
        //const uint VOLUME_SET_1_95 = 0x00401FC8;
        //const byte[] VOLUME_SET_1_95_CODE[] = {0x58,0x8B,0x08,0x6A,0x01,0xEB,0x16,0x90,0xE9,0xCB,0x85,0x01,0x00,0x58,0x8B,0x08,
        //                             0x6A,0x00,0xEB,0x09,0x90,0x90,0x90,0x90,0xE9,0xAB,0x85,0x01,0x00,0x6A,0x00,0x6A,
        //                             0x00,0x50,0xFF,0x51,0x30,0x5B,0xC3};
        //const uint VOLUME_SET_2_95 = 0x0040203F;
        //const byte[] VOLUME_SET_2_95_CODE[] = {0x50,0x8B,0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x7B,0xFF,0xFF,0xFF,0x50,0x8B,
        //                             0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x7A,0xFF,0xFF,0xFF};

        // Determines MS version integer.
        const uint MS_VERSION = 100;

        // Maximums
        const uint MAX_NAME = 32;
        const uint MAX_ARRAY = 64;
        const uint MAX_ID = 0x3FFF;
        const uint MAX_TITLE = 256;
        const uint MAX_PACKET = 512;
        const uint MAX_WELCOME = 512;
        const uint MAX_KEYWORD = 256;
        const uint MAX_PROFILE = 2048;

        //const byte[] TYMT_VERSION = BitConverter.GetBytes(6);
        public static byte[] TYMT_VERSTION = BitConverter.GetBytes(6);
        const uint TIME_OUT = 3000;

        void WriteErrorLog(String text, String caption)
        {
           
            DirectoryInfo[] cDirs = new DirectoryInfo(Properties.Settings.Default.Path).GetDirectories();

            //new String(test) + "error.log", Encoding.Default
            using (StreamWriter sw = new StreamWriter("error.log", true, Encoding.Default))
                try
                {
                    sw.WriteLine();
                }
                finally
                {
                    if (sw != null)
                    {
                        sw.Close();
                        sw.Dispose();
                    }
                }
        }


        void ApplicationThreadException(Object sender, ThreadExceptionEventArgs e)
        {
            WriteErrorLog(e.ToString(), "ThreadException");
            //MTINFO.ERRORED = true;
        }



        // This is essentially a sanity checker now
        public void Converter()
        {
            foreach (byte b in SINGLE_CONTROL_HOOK_CODE)
            {
                Console.WriteLine(b.ToString());
            }
        }
    }
}
