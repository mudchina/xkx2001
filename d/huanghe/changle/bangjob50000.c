//Cracked by Roath
// /d/huanghe/changle/bangjob50000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "哈萨克",
                "file"  :  "/d/xingxiu/npc/hasake",
                "area"  :  "天山脚下",
                "type"  :  "杀",
                "bonus" :  15,
                "score" :  4,
        ]), 

        ([      "name"  :  "袁冠男",
                "file"  :  "/d/forest/npc/guannan",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  12,
        ]), 

        ([      "name"  :  "林玉龙",
                "file"  :  "/d/forest/npc/lin",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "任飞燕",
                "file"  :  "/d/forest/npc/ren",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "祖千秋",
                "file"  :  "/d/huanghe/npc/qiu",
                "area"  :  "黄河岸边",
                "type"  :  "杀",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "萧中慧",
                "file"  :  "/d/forest/npc/zhonghui",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "向问天",
                "file"  :  "/d/jiaxing/npc/xiang",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  60,
                "score" :  20,
        ]),

        ([      "name"  :  "贾人达",
                "file"  :  "/d/quanzhou/npc/jiarenda",
                "area"  :  "泉州山路",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "type"  :  "截镖",
        ]),

        ([      "type"  :  "截镖",
        ]),

        ([      "type"  :  "截镖",
        ]),

        ([      "type"  :  "截镖",
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

