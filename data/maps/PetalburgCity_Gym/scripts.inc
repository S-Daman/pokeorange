PetalburgCity_Gym_MapScripts::
	.byte 0


MikanGymGloryBoard::
	lockall
	goto_if_set FLAG_BADGE01_GET, MikanGymGloryBoard_2
	msgbox MikanGymGloryBoard_Text_1, MSGBOX_SIGN
	releaseall
	end

MikanGymGloryBoard_2:
	msgbox MikanGymGloryBoard_Text_0, MSGBOX_SIGN
	releaseall
	end


MikanGymDude::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, MikanGymDude_2
	msgbox MikanGymDude_Text_1, MSGBOX_DEFAULT
	release
	end

MikanGymDude_2:
	msgbox MikanGymDude_Text_0, MSGBOX_DEFAULT
	release
	end


MikanGymTuber::
	trainerbattle_single TRAINER_HAILEY, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated
	msgbox Route109_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
	end


MikanGymSwimmer::
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated
	msgbox Route105_Text_PostBattle, MSGBOX_AUTOCLOSE
	end


MikanGymGloryBoard_Text_0:
	.string "MIKAN POKéMON GYM\nLEADER: CISSY\pWINNING TRAINERS:\nCORA, {PLAYER}$"

MikanGymGloryBoard_Text_1:
	.string "MIKAN POKéMON GYM\nLEADER: CISSY\pWINNING TRAINERS:\nCORA$"

MikanGymDude_Text_0:
	.string "Whoa, that was a splendid battle!\nMy advice must've worked!\pHave you checked your TRAINER CARD?\pThe CORAL-EYE BADGE you earned\nshould be displayed on it.\pDo you realize what you've just\ndone?\pYou've climbed the first step on\nthe ladder to the CHAMPIONSHIP!\pThat's gotta be an awesome feeling,\nam I right?$"

MikanGymDude_Text_1:
	.string "So, my friend, do you dream to\nbecome the CHAMPION?\pI'm not a TRAINER, nope, but I\ncan give you some useful advice.\pAlright, let's aim for the\nORANGE LEAGUE together!\pYour job is to defeat the\nORANGE CREW and collect GYM BADGES.\pBut beware, the ORANGE CREW is no joke!\pAnd that's where you need my help!\nI provide expert advice!\pThis GYM is run by CISSY.\nShe uses WATER TYPE POKéMON.\pWATER POKéMON don't stand a chance\nagainst GRASS or ELECTRIC TYPE moves.\pCome see me once you've beaten her!\nGo for it, TRAINER!$"
