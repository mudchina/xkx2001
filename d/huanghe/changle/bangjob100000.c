//Cracked by Roath
// /d/huanghe/bangjob/bangjob100000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "Ïô°ëºÍ",
                "file"  :  "/d/forest/npc/banhe",
                "area"  :  "ÑïÖÝ½¼Íâ",
                "type"  :  "É±",
                "bonus" :  50,
                "score" :  15,
        ]),

        ([      "name"  :  "ºîÍ¨º£",
                "file"  :  "/d/huanghe/npc/hou-tonghai",
                "area"  :  "»ÆºÓ°¶±ß",
                "type"  :  "É±",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "ÆÝ³¤·¢",
                "file"  :  "/d/foshan/npc/changfa",
                "area"  :  "ÏæÎ÷",
                "type"  :  "É±",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "»ÆÖÓ¹«",
                "file"  :  "/d/jiaxing/npc/huang",
                "area"  :  "º¼ÖÝÃ·×¯",
                "type"  :  "É±",
                "bonus" :  75,
                "score" :  25,
        ]),

        ([      "name"  :  "ºÚ°××Ó",
                "file"  :  "/d/jiaxing/npc/heibai",
                "area"  :  "º¼ÖÝÃ·×¯",
                "type"  :  "É±",
                "bonus" :  70,
                "score" :  20,
        ]),

        ([      "name"  :  "Íº±ÊÎÌ",
                "file"  :  "/d/jiaxing/npc/tubiweng",
                "area"  :  "º¼ÖÝÃ·×¯",
                "type"  :  "É±",
                "bonus" :  65,
                "score" :  20,
        ]),

        ([      "name"  :  "µ¤ÇàÉú",
                "file"  :  "/d/jiaxing/npc/danqing",
                "area"  :  "º¼ÖÝÃ·×¯",
                "type"  :  "É±", 
                "bonus" :  60,
                "score" :  17,
        ]),

        ([      "name"  :  "¶¡¼á",
                "file"  :  "/d/jiaxing/npc/dingjian",
                "area"  :  "º¼ÖÝÃ·×¯",
                "type"  :  "É±",
                "bonus" :  45,
                "score" :  10,
        ]),

        ([      "name"  :  "Ê©ÁîÍþ",
                "file"  :  "/d/jiaxing/npc/shilingwei",
                "area"  :  "º¼ÖÝÃ·×¯",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  10,
        ]),

        ([      "name"  :  "Â½¹ÚÓ¢",
                "file"  :  "/d/taihu/npc/guanying",
                "area"  :  "¹éÔÆ×¯",
                "type"  :  "É±",
                "bonus" :  60,
                "score" :  20,
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
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

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}

