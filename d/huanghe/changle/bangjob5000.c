//Cracked by Roath
// /d/huanghe/changle/bangjob5000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "回回",
                "file"  :  "/d/quanzhou/npc/huihui",
                "area"  :  "泉州",
                "type"  :  "杀",
                "bonus" :  18,
                "score" :  4,
        ]),

        ([      "name"  :  "塘工",
                "file"  :  "/d/hangzhou/npc/tbbz",
                "area"  :  "杭州湾海堤",
                "type"  :  "杀",
                "bonus" :  15,
                "score" :  3,
        ]),

        ([      "name"  :  "海沙派盐枭",
                "file"  :  "/d/hangzhou/npc/hsbz",
                "area"  :  "杭州湾盐田",
                "type"  :  "杀",
                "bonus" :  18,
                "score" :  5,
        ]),

        ([      "name"  :  "天鹰教众",
                "file"  :  "/d/hangzhou/npc/tyjz",
                "area"  :  "杭州湾海神庙",
                "type"  :  "杀",
                "bonus" :  20,
                "score" :  5,
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
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


