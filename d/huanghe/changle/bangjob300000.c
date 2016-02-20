//Cracked by Roath
// /d/huanghe/bangjob/bangjob300000.c
// by aln / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "±¦Ê÷",
                "file"  :  "/d/foshan/npc/baoshu",
                "area"  :  "ÉÙÁÖËÂ",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "Áº×ÓÎÌ",
                "file"  :  "/d/huanghe/npc/liang-ziweng",
                "area"  :  "»ÆºÓ°ï",
                "type"  :  "É±",
                "bonus" :  70,
                "score" :  30,
        ]),

        ([      "name"  :  "ÈÕ±¾ÀËÈË",
                "file"  :  "/d/quanzhou/npc/langren",
                "area"  :  "ÈªÖÝ",
                "type"  :  "É±",
                "bonus" :  30,
                "score" :  7,
        ]),

        ([      "name"  :  "ÑîÌúÐÄ",
                "file"  :  "/d/hangzhou/npc/yang",
                "area"  :  "Å£¼Ò´å",
                "type"  :  "É±",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "¹ùÐ¥Ìì",
                "file"  :  "/d/hangzhou/npc/guo",
                "area"  :  "Å£¼Ò´å",
                "type"  :  "É±",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "»¢¹Ç",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "ÐÜµ¨",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "Ö¸»·",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "Ê¾Íþ",
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

        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
