//Cracked by Roath
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "¶¡µä",
                "file"  :  "/d/city/npc/dingdian",
                "area"  :  "ÑïÖÝ³Ç¼àÓü",
                "type"  :  "É±",
                "bonus" :  100,
                "score" :  40,
        ]),

        ([      "name"  :  "ëøÒ»À×",
                "file"  :  "/d/changbai/npc/teng",
                "area"  :  "¹Ø¶«",
                "type"  :  "É±",
                "bonus" :  70,
                "score" :  20,
        ]),

        ([      "name"  :  "ÅíÁ¬»¢",
                "file"  :  "/d/forest/npc/peng-lianhu",
                "area"  :  "»ÆºÓ°ï",
                "type"  :  "É±",
                "bonus" :  60,
                "score" :  15,
        ]),

        ([      "name"  :  "ÐþÌúÁî",
                "file"  :  " ",
                "type"  :  "Ñ°",
                "bonus" :  50,
                "score" :  12,
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
