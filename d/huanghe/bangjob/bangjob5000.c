//Cracked by Roath
// /d/huanghe/bangjob/bangjob5000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "镖头",
                "file"  :  "/d/city/npc/biaotou",
                "area"  :  "扬州福威镖局",
                "type"  :  "杀",
                "bonus" :  20,
                "score" :  6,
        ]),

        ([      "name"  :  "家丁",
                "file"  :  "/d/city/npc/jiading",
                "area"  :  "扬州翰林府院",
                "type"  :  "杀",
                "bonus" :  15,
                "score" :  3,
        ]),

        ([      "name"  :  "菊友",
                "file"  :  "/d/city/npc/juyou",
                "area"  :  "扬州翰林府院",
                "type"  :  "杀",
                "bonus" :  15,
                "score" :  4,
        ]),

        ([      "name"  :  "王小二",
                "file"  :  "/d/village/npc/wang",
                "area"  :  "华山村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  15,
        ]),

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
                "score" :  4,
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

        ([      "name"  :  "令牌",
                "file"  :  "/d/city/obj/lingpai",
                "type"  :  "寻",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "砍刀",
                "file"  :  "/d/dali/npc/obj/kandao",
                "type"  :  "寻",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "竹筒",
                "file"  :  "/d/dali/obj/zhutong",
                "type"  :  "寻",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "铁锤",
                "file"  :  "/clone/weapon/hammer",
                "type"  :  "寻",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "乌夷大麾",
                "file"  :  "/d/dali/npc/obj/wyhui",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "name"  :  "乌夷长裙",
                "file"  :  "/d/dali/npc/obj/wyskirt",
                "type"  :  "寻",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "羊鞭",
                "file"  :  "/d/xingxiu/obj/bian",
                "type"  :  "寻",
                "bonus" :  12,
                "score" :  4,
        ]),

        ([      "name"  :  "长鞭",
                "file"  :  "/d/xingxiu/obj/changbian",
                "type"  :  "寻",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "波斯长袍",
                "file"  :  "/d/xingxiu/obj/changpao",
                "type"  :  "寻",
                "bonus" :  8,
                "score" :  3,
        ]),

        ([      "name"  :  "冬不拉",
                "file"  :  "/d/xingxiu/obj/dongbula",
                "type"  :  "寻",
                "bonus" :  10,
                "score" :  4,
        ]),

        ([      "name"  :  "蒙汗药",
                "file"  :  "/d/xingxiu/obj/menghan_yao",
                "type"  :  "寻",
                "bonus" :  6,
                "score" :  2,
        ]),

        ([      "name"  :  "化尸粉",
                "file"  :  "/d/xingxiu/obj/huashi",
                "type"  :  "寻",
                "bonus" :  12,
                "score" :  5,
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
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


