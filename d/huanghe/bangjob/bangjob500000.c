//Cracked by Roath
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "ÓàÓãÍ¬",
                "file"  :  "/d/city/npc/yutong",
                "area"  :  "ÑïÖÝÌá¶½¸®",
                "type"  :  "É±",
                "bonus" :  60,
                "score" :  20,
        ]),

        ([      "name"  :  "¶¡µä",
                "file"  :  "/d/city/npc/dingdian",
                "area"  :  "ÑïÖÝ³Ç¼àÓü",
                "type"  :  "É±",
                "bonus" :  90,
                "score" :  35,
        ]),

        ([      "name"  :  "Â½¸ßÖ¹",
                "file"  :  "/d/city/npc/gaozhi",
                "area"  :  "ÑïÖÝÌá¶½¸®",
                "type"  :  "É±",
                "bonus" :  90,
                "score" :  45,
        ]),

        ([      "name"  :  "ÕÔÁ¼¶°",
                "file"  :  "/d/city/npc/shi",
                "area"  :  "ÑïÖÝ³Ç±øÓª",
                "type"  :  "É±",
                "bonus" :  60,
                "score" :  30,
        ]),

        ([      "name"  :  "ëøÒ»À×",
                "file"  :  "/d/changbai/npc/teng",
                "area"  :  "¹Ø¶«",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "ÅíÁ¬»¢",
                "file"  :  "/d/huanghe/npc/peng-lianhu",
                "area"  :  "»ÆºÓ°ï",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "¶À×ãÍ­ÈË",
                "file"  :  "/d/changbai/obj/tongren",
                "type"  :  "Ñ°",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "¸Ö×¦",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "ÉÕºìµÄÌú´¸",
                "file"  :  " ",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "ÐþÌúÁî",
                "file"  :  " ",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "ºÚÁú±Þ",
                "file"  :  " ",
                "type"  :  "Ñ°",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "Çà¸Õ½£",
                "file"  :  "/d/changbai/obj/qinggang-jian",
                "type"  :  "Ñ°",
                "bonus" :  30,
                "score" :  15,
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "»¤¼Ý",
        ]),

        ([      "type"  :  "»¤¼Ý",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
