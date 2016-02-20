//Cracked by Roath
// /d/huanghe/changle/bangjob3000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "进香客",
                "file"  :  "/d/emei/npc/xiang-ke",
                "area"  :  "峨眉山",
                "type"  :  "杀",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "皮货商",
                "file"  :  "/d/changbai/npc/phshang",
                "area"  :  "长白山集市",
                "type"  :  "杀",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "胖商人",
                "file"  :  "/d/foshan/npc/pang",
                "area"  :  "佛山镇",
                "type"  :  "杀",
                "bonus" :  5,
                "score" :  1,
        ]),

        ([      "name"  :  "瘦商人",
                "file"  :  "/d/foshan/npc/shou",
                "area"  :  "佛山镇",
                "type"  :  "杀",
                "bonus" :  5,
                "score" :  1,
        ]),

        ([      "name"  :  "小贩",
                "file"  :  "/d/quanzhou/npc/mao-fan",
                "area"  :  "泉州中心广场",
                "type"  :  "杀",
                "bonus" :  6,
                "score" :  2,
        ]),

        ([      "name"  :  "野菊花",
                "file"  :  "/d/city/obj/juhua",
                "type"  :  "寻",
                "bonus" :  3,
                "score" :  1,
        ]),

        ([      "name"  :  "狗皮",
                "file"  :  "/d/city/obj/goupi",
                "type"  :  "寻",
                "bonus" :  3,
                "score" :  1,
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}



