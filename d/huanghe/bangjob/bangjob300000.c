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

        ([      "name"  :  "»Û½ð×ðÕß",
                "file"  :  "/d/quanzhou/npc/huijin",
                "area"  :  "ÈªÖÝ",
                "type"  :  "É±",
                "bonus" :  35,
                "score" :  15,
        ]),

        ([      "name"  :  "ÈÕ±¾ÀËÈË",
                "file"  :  "/d/quanzhou/npc/langren",
                "area"  :  "ÈªÖÝ",
                "type"  :  "É±",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "Ê©ÀÅ",
                "file"  :  "/d/quanzhou/npc/shilang",
                "area"  :  "ÈªÖÝ",
                "type"  :  "É±",
                "bonus" :  80,
                "score" :  40,
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

        ([      "name"  :  "ÌúÅÆ",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  12,
                "score" :  3,
        ]),

        ([      "name"  :  "Ö¸»·",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "name"  :  "ÀÇÑÀ°ô",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  15,
                "score" :  4,
        ]),

        ([      "name"  :  "»ÕÄ«",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "½ðËãÅÌ",
                "file"  :  "/d/dali/npc/obj/jinsuanpan",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  6,
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
