//Cracked by Roath
// /d/shenlong/sgjob/sgjob100000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *sgjobs = ({
        ([      "sgjob":          "åÐÒ£ÈýÐ¦É¢",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             100,
                "score":                 2,
        ]),

        ([      "sgjob":          "ÌúÇò",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             200,
                "score":                 3,
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_sgjob()
{
        return sgjobs[random(sizeof(sgjobs))];
}




