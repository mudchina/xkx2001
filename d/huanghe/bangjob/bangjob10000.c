//Cracked by Roath
// /d/huanghe/bangjob/bangjob10000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "官兵",
                "file"  :  "/d/city/npc/bing",
                "area"  :  "扬州城",
                "type"  :  "杀",
                "bonus" :  25,
                "score" :  12,
        ]),

        ([      "name"  :  "管家",
                "file"  :  "/d/city/npc/guanjia",
                "area"  :  "扬州翰林府院",
                "type"  :  "杀",
                "bonus" :  10,
                "score" :  4,
        ]),

        ([      "name"  :  "林平之",
                "file"  :  "/d/city/npc/linpingzhi",
                "area"  :  "扬州福威镖局",
                "type"  :  "杀",
                "bonus" :  17,
                "score" :  6,
        ]),

        ([      "name"  :  "流氓头",
                "file"  :  "/d/city/npc/liumangtou",
                "area"  :  "扬州城中心",
                "type"  :  "杀",
                "bonus" :  12,
                "score" :  5,
        ]),

        ([      "name"  :  "衙役",
                "file"  :  "/d/city/npc/yayi",
                "area"  :  "扬州城",
                "type"  :  "杀",
                "bonus" :  20,
                "score" :  10,
        ]),

        ([      "name"  :  "赫尔苏",
                "file"  :  "/d/changbai/npc/batou",
                "area"  :  "长白山",
                "type"  :  "杀",
                "bonus" :  15,
                "score" :  4,
        ]),

        ([      "name"  :  "盖一鸣",
                "file"  :  "/d/forest/npc/gaiyiming",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  10,
        ]),

        ([      "name"  :  "沈青刚",
                "file"  :  "/d/huanghe/npc/shen-qinggang",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  20,
                "score" :  6,
        ]),

        ([      "name"  :  "吴青烈",
                "file"  :  "/d/huanghe/npc/wu-qinglie",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  18,
                "score" :  6,
        ]),

        ([      "name"  :  "马青雄",
                "file"  :  "/d/huanghe/npc/ma-qingxiong",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  16,
                "score" :  5,
        ]),

        ([      "name"  :  "钱青健",
                "file"  :  "/d/huanghe/npc/qian-qingjian",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "裘万家",
                "file"  :  "/kungfu/class/gaibang/qiu-wanjia",
                "area"  :  "南阳迎宾楼",
                "type"  :  "杀",
                "bonus" :  16,
                "score" :  5,
        ]),

        ([      "name"  :  "胡人",
                "file"  :  "/d/quanzhou/npc/huren",
                "area"  :  "泉州",
                "type"  :  "杀",
                "bonus" :  12,
                "score" :  3,
        ]),

        ([      "name"  :  "武馆门丁",
                "file"  :  "/d/quanzhou/npc/mending",
                "area"  :  "泉州扬威武馆",
                "type"  :  "杀",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "僧人",
                "file"  :  "/d/quanzhou/npc/monk",
                "area"  :  "泉州",
                "type"  :  "杀",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "阿拉伯商人",
                "file"  :  "/d/quanzhou/npc/trader",
                "area"  :  "泉州",
                "type"  :  "杀",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "游方和尚",
                "file"  :  "/d/taishan/npc/seng-ren",
                "area"  :  "泰山",
                "type"  :  "杀",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "土匪",
                "file"  :  "/d/wudang/npc/tufei1",
                "area"  :  "武当山",
                "type"  :  "杀",
                "bonus" :  25,
                "score" :  12,
        ]),

        ([      "name"  :  "短剑",
                "file"  :  "/clone/weapon/duanjian",
                "type"  :  "寻",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "钢刀",
                "file"  :  "/clone/weapon/gangdao",
                "type"  :  "寻",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "军服",
                "file"  :  "/d/city/npc/obj/junfu",
                "type"  :  "寻",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "衙役服",
                "file"  :  "/d/city/npc/obj/yayifu",
                "type"  :  "寻",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "短刀",
                "file"  :  "/d/dali/obj/duandao",
                "type"  :  "寻",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "大红袈裟",
                "file"  :  "/d/forest/npc/obj/dahong-jiasha",
                "type"  :  "寻",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "峨眉刺",
                "file"  :  "/d/forest/npc/obj/emeici",
                "type"  :  "寻",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "type"  :  "截镖",
        ]),

        ([      "type"  :  "截镖",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


