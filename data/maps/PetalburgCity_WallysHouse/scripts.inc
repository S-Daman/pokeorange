PetalburgCity_WallysHouse_MapScripts::
	.byte 0


MikanSchoolNotebook::
	lockall
	msgbox MikanSchoolNotebook_Text_0, MSGBOX_DEFAULT
	msgbox TurnPage, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MikanSchoolNotebook_2
	msgbox MikanSchoolNotebook_Text_1, MSGBOX_DEFAULT
	msgbox TurnPage, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MikanSchoolNotebook_5
	msgbox MikanSchoolNotebook_Text_2, MSGBOX_DEFAULT
	msgbox TurnPage, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MikanSchoolNotebook_8
	msgbox MikanSchoolNotebook_Text_3, MSGBOX_DEFAULT
	releaseall
	end

MikanSchoolNotebook_2:
	releaseall
	end

MikanSchoolNotebook_5:
	releaseall
	end

MikanSchoolNotebook_8:
	releaseall
	end


MikanSchoolTeacher::
	lock
	faceplayer
	msgbox MikanSchoolTeacher_Text_0, MSGBOX_AUTOCLOSE
	delay 5
	turnobject 2, 1
	release
	return


MikanSchoolStudent::
	lock
	faceplayer
	msgbox MikanSchoolStudent_Text_0, MSGBOX_AUTOCLOSE
	delay 5
	turnobject 1, 2
	release
	return


MikanSchoolNotebook_Text_0:
	.string "Let's check out the notebook.\pFirst page…\pPOKé BALLS are used to catch\nPOKéMON.\pUp to six POKéMON can be carried\nin your party.\pPeople who raise and battle\nwith POKéMON are called TRAINERS.$"

MikanSchoolNotebook_Text_1:
	.string "Second page…\pA healthy POKéMON may be hard to\ncatch, so weaken it first.\pPoison, burn, or cause another\nstatus problem to weaken it.$"

MikanSchoolNotebook_Text_2:
	.string "Third page…\pPOKéMON TRAINERS seek others to\nengage in POKéMON battles.\pTo TRAINERS, the taste of victory\nis sweet, indeed.\pBattles are constantly waged at\nPOKéMON GYMS everywhere.$"

MikanSchoolNotebook_Text_3:
	.string "Fourth page…\pThe ultimate goal for all POKéMON\nTRAINERS is simple.\pIt is to defeat the top eight\nPOKéMON GYM LEADERS.\pDo so to earn the right to face…\pThe ELITE FOUR of the POKéMON\nLEAGUE!\pThe next page is…\nBlank!$"

MikanSchoolTeacher_Text_0:
	.string "Alright!\pRemember to copy down everything\non the blackboard carefully!$"

MikanSchoolStudent_Text_0:
	.string "Whew! I'm trying to memorize all my\nnotes.\pThe teacher is too strict…$"

TurnPage::
	.string "Turn the page?$"
