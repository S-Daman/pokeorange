RustboroCity_MapScripts::
	.byte 0


SunburstSign::
	msgbox SunburstSign_Text_0, MSGBOX_SIGN
	release
	end


SunburstGirl::
	lock
	faceplayer
	msgbox SunburstGirl_Text_0, MSGBOX_AUTOCLOSE
	release
	end


SunburstLittleGirl::
	lock
	faceplayer
	msgbox SunburstLittleGirl_Text_0, MSGBOX_AUTOCLOSE
	release
	end


SunburstOldMan::
	lock
	faceplayer
	msgbox SunburstOldMan_Text_0, MSGBOX_AUTOCLOSE
	release
	end


SunburstFatass::
	lock
	faceplayer
	msgbox SunburstFatass_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MateoDoorLock::
	msgbox MateoDoorLock_Text_0, MSGBOX_SIGN
	release
	end


CrystalShop::
	msgbox CrystalShop_Text_0, MSGBOX_SIGN
	release
	end


Bazaar::
	msgbox Bazaar_Text_0, MSGBOX_SIGN
	release
	end


CrystalCave1::
	msgbox CrystalCave1_Text_0, MSGBOX_SIGN
	release
	end


SunburstSign_Text_0:
	.string "SUNBURST ISLAND\nTolerance is Sour, but its Fruit is Sweet$"

SunburstGirl_Text_0:
	.string "It's true that they have some\ninteresting merchandise at the\lBAZAAR over here, but some items are\lonly obtainable at POKéMON MARTS.$"

SunburstLittleGirl_Text_0:
	.string "My big brother used to make\nglass sculptures on the tiny island\lwest of town.\pIt let him focus on his art since\nhis shop was isolated from the\lbustling BAZAAR noises.\pUnfortunately, he started to lose\ninspiration towards his work, and the\lfact that he was no longer getting\lcustomers caused him to quit.\pSo, he left town to look for work\nsomewhere else.\pI hope he is taking care of himself… $"

SunburstOldMan_Text_0:
	.string "This used to be a well-off town,\nlike MANDARIN ISLAND NORTH was.\pWe have been getting fewer\nvisitors lately, and it has caused\lour businesses to suffer.$"

SunburstFatass_Text_0:
	.string "Ahead lies CRYSTAL CAVE.\pLegend has it than an ONIX made of\ncrystal lives inside.\pSpeaking of ONIX, a GYM LEADER\nfrom the KANTO REGION came by earlier.$"

MateoDoorLock_Text_0:
	.string "The door is locked.$"

CrystalShop_Text_0:
	.string "CRYSTAL SHOP\pOut of Business$"

Bazaar_Text_0:
	.string "SUNBURST BAZAAR$"

CrystalCave1_Text_0:
	.string "CRYSTAL CAVE\n{RIGHT_ARROW} ROUTE 52$"
