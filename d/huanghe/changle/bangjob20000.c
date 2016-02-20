//Cracked by Roath
// /d/huanghe/bangjob/bangjob20000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "王五",
                "file"  :  "/d/city/npc/guidao",
                "area"  :  "扬州醉仙楼",
                "type"  :  "杀",
                "bonus" :  20,
                "score" :  6,
        ]),

        ([      "name"  :  "空空儿",
                "file"  :  "/d/city/npc/qigai.c",
                "area"  :  "扬州城",
                "type"  :  "杀",
                "bonus" :  50,
                "score" :  20,
        ]),

        ([      "name"  :  "常长风",
                "file"  :  "/d/forest/npc/chang",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "花剑影",
                "file"  :  "/d/forest/npc/hua",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "逍遥子",
                "file"  :  "/d/forest/npc/xiaoyaozi",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "刀客",
                "file"  :  "/d/taishan/npc/dao-ke",
                "area"  :  "泰山",
                "type"  :  "杀",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "剑客",
                "file"  :  "/d/taishan/npc/jian-ke",
                "area"  :  "泰山",
                "type"  :  "杀",
                "bonus" :  12,
                "score" :  3,
        ]),

        ([      "name"  :  "土匪头",
                "file"  :  "/d/wudang/npc/tufeitou",
                "area"  :  "武当山",
                "type"  :  "杀",
                "bonus" :  50,
                "score" :  17,
        ]),

        ([      "name"  :  "广陵散",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "率意帖",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "棋谱",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "行旅图",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  10,
                "score" :  3,
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
