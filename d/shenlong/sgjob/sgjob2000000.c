//Cracked by Roath
// /d/shenlong/sgjob/sgjob2000000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *sgjobs = ({
        ([      "sgjob":          "“–ÃÏΩ£",
                "sgjob_type":           "—∞",
                "exp_bonus":             1500,
                "pot_bonus":             300,
                "score":                 40,
        ]),

        ([      "sgjob":          "”ÒÛÔ",
                "sgjob_type":           "—∞",
                "exp_bonus":             2000,
                "pot_bonus":             300,
                "score":                 50,
        ]),

        ([      "sgjob":          "»Ì‚¨º◊",
                "sgjob_type":           "—∞",
                "exp_bonus":             2000,
                "pot_bonus":             300,
                "score":                 50,
        ]),

        ([      "sgjob":          "–˛Ã˙÷ÿΩ£",
                "sgjob_type":           "—∞",
                "exp_bonus":             1500,
                "pot_bonus":             300,
                "score":                 40,
        ]),

        ([      "sgjob":          "’ÊŒ‰Ω£",
                "sgjob_type":           "—∞",
                "exp_bonus":             2500,
                "pot_bonus":             300,
                "score":                 60,
        ]),

        ([      "sgjob":          "”Ò÷Ò’»",
                "sgjob_type":           "—∞",
                "exp_bonus":             2000,
                "pot_bonus":             300,
                "score":                 50,
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
});

void create() { seteuid(getuid()); }

mapping query_sgjob()
{
        return sgjobs[random(sizeof(sgjobs))];
}
