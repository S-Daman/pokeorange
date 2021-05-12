GraniteCave_1F_MapScripts::
	.byte 0


CrystalCaveBrock::
	lockall
	setvar VAR_ROUTE105_STATE, 9
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 26
	goto_if_eq CrystalCaveBrock_2
	compare VAR_TEMP_1, 27
	goto_if_eq CrystalCaveBrock_5
	compare VAR_TEMP_1, 28
	goto_if_eq CrystalCaveBrock_10
	return

CrystalCaveBrock_2:
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, CrystalCaveF1_Brock_Camera
	waitmovement 0
	applymovement 3, CrystalCaveF1_Brock_Exclamation
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	applymovement 3, CrystalCaveF1_Brock_Move1
	applymovement EVENT_OBJ_ID_CAMERA, CrystalCaveF1_Brock_CameraEnd
	waitmovement 3
	special RemoveCameraObject
	msgbox CrystalCaveBrock_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CrystalCaveBrock_8
	msgbox CrystalCaveBrock_Text_2, MSGBOX_AUTOCLOSE
	applymovement 3, CrystalCaveF1_Brock_Move2
	waitmovement 0
	removeobject 3
	setflag FLAG_UNUSED_0x02F
	releaseall
	end

CrystalCaveBrock_5:
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, CrystalCaveF1_Brock_Camera_1
	waitmovement 0
	applymovement 3, CrystalCaveF1_Brock_Exclamation
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	applymovement 3, CrystalCaveF1_Brock_Move1_1
	applymovement EVENT_OBJ_ID_CAMERA, CrystalCaveF1_Brock_CameraEnd_1
	waitmovement 3
	special RemoveCameraObject
	msgbox CrystalCaveBrock_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CrystalCaveBrock_13
	msgbox CrystalCaveBrock_Text_2, MSGBOX_AUTOCLOSE
	applymovement 3, CrystalCaveF1_Brock_Move2
	waitmovement 0
	removeobject 3
	setflag FLAG_UNUSED_0x02F
	releaseall
	end

CrystalCaveBrock_8:
	msgbox CrystalCaveBrock_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, CrystalCaveF1_Brock_Move2
	waitmovement 0
	removeobject 3
	setflag FLAG_UNUSED_0x02F
	releaseall
	end

CrystalCaveBrock_10:
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, CrystalCaveF1_Brock_Camera_2
	waitmovement 0
	applymovement 3, CrystalCaveF1_Brock_Exclamation
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	applymovement 3, CrystalCaveF1_Brock_Move1_2
	applymovement EVENT_OBJ_ID_CAMERA, CrystalCaveF1_Brock_CameraEnd_2
	waitmovement 3
	special RemoveCameraObject
	msgbox CrystalCaveBrock_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CrystalCaveBrock_16
	msgbox CrystalCaveBrock_Text_2, MSGBOX_AUTOCLOSE
	applymovement 3, CrystalCaveF1_Brock_Move2
	waitmovement 0
	removeobject 3
	setflag FLAG_UNUSED_0x02F
	releaseall
	end

CrystalCaveBrock_13:
	msgbox CrystalCaveBrock_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, CrystalCaveF1_Brock_Move2
	waitmovement 0
	removeobject 3
	setflag FLAG_UNUSED_0x02F
	releaseall
	end

CrystalCaveBrock_16:
	msgbox CrystalCaveBrock_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, CrystalCaveF1_Brock_Move2
	waitmovement 0
	removeobject 3
	setflag FLAG_UNUSED_0x02F
	releaseall
	end


CrystalCaveF1_Brock_Exclamation:
	face_down
	emote_exclamation_mark
	step_end

CrystalCaveF1_Brock_Camera:
	walk_right
	walk_right
	step_end

CrystalCaveF1_Brock_CameraEnd:
	delay_16
	delay_16
	walk_left
	walk_left
	step_end

CrystalCaveF1_Brock_Move1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CrystalCaveF1_Brock_Move2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CrystalCaveF1_Brock_Camera_1:
	walk_right
	walk_right
	walk_up
	step_end

CrystalCaveF1_Brock_CameraEnd_1:
	delay_16
	delay_16
	walk_down
	walk_left
	walk_left
	step_end

CrystalCaveF1_Brock_Move1_1:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CrystalCaveF1_Brock_Camera_2:
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

CrystalCaveF1_Brock_CameraEnd_2:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

CrystalCaveF1_Brock_Move1_2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CrystalCaveBrice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat, Route112_Brice_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq CrystalCaveBrice_2
CrystalCaveBrice_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq CrystalCaveBrice_5
CrystalCaveBrice_4:
	msgbox Route112_Text_BricePostBattle, MSGBOX_DEFAULT
	release
	end

CrystalCaveBrice_2:
	goto Route112_Brice_Rematch
	goto CrystalCaveBrice_1

CrystalCaveBrice_5:
	goto Route112_Brice_CheckMatchCall2
	goto CrystalCaveBrice_4


Route112_Brice_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route112_Brice_CheckMatchCall_2
Route112_Brice_CheckMatchCall_1:
	release
	end

Route112_Brice_CheckMatchCall_2:
	goto Route112_Brice_RegisterShortMatchCall
	goto Route112_Brice_CheckMatchCall_1


Route112_Brice_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRICE
	release
	end


Route112_Brice_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route112_Brice_CheckMatchCall2_2
Route112_Brice_CheckMatchCall2_1:
	msgbox Route112_Text_BricePostBattle, MSGBOX_DEFAULT
	release
	end

Route112_Brice_CheckMatchCall2_2:
	goto Route112_Brice_RegisterMatchCall
	goto Route112_Brice_CheckMatchCall2_1


Route112_Brice_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRICE
	release
	end


Route112_Brice_Rematch::
	trainerbattle_rematch TRAINER_BRICE, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


CrystalCaveBryan::
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat, Route111_Bryan_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq CrystalCaveBryan_2
CrystalCaveBryan_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq CrystalCaveBryan_5
CrystalCaveBryan_4:
	msgbox Route111_Text_BryanPostBattle, MSGBOX_DEFAULT
	release
	end

CrystalCaveBryan_2:
	goto Route111_Bryan_Rematch
	goto CrystalCaveBryan_1

CrystalCaveBryan_5:
	goto Route111_Bryan_CheckMatchCall2
	goto CrystalCaveBryan_4


Route111_Bryan_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route111_Bryan_CheckMatchCall_2
Route111_Bryan_CheckMatchCall_1:
	release
	end

Route111_Bryan_CheckMatchCall_2:
	goto Route111_Bryan_RegisterShortMatchCall
	goto Route111_Bryan_CheckMatchCall_1


Route111_Bryan_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRYAN
	release
	end


Route111_Bryan_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route111_Bryan_CheckMatchCall2_2
Route111_Bryan_CheckMatchCall2_1:
	msgbox Route111_Text_BryanPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_Bryan_CheckMatchCall2_2:
	goto Route111_Bryan_RegisterMatchCall
	goto Route111_Bryan_CheckMatchCall2_1


Route111_Bryan_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRYAN
	release
	end


Route111_Bryan_Rematch::
	trainerbattle_rematch TRAINER_BRYAN, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


CrystalCaveCale::
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat, Route121_Cale_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq CrystalCaveCale_2
CrystalCaveCale_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq CrystalCaveCale_5
CrystalCaveCale_4:
	msgbox Route121_Text_CalePostBattle, MSGBOX_DEFAULT
	release
	end

CrystalCaveCale_2:
	goto Route121_Cale_Rematch
	goto CrystalCaveCale_1

CrystalCaveCale_5:
	goto Route121_Cale_CheckMatchCall2
	goto CrystalCaveCale_4


Route121_Cale_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route121_Cale_CheckMatchCall_2
Route121_Cale_CheckMatchCall_1:
	release
	end

Route121_Cale_CheckMatchCall_2:
	goto Route121_Cale_RegisterShortMatchCall
	goto Route121_Cale_CheckMatchCall_1


Route121_Cale_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALE
	release
	end


Route121_Cale_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route121_Cale_CheckMatchCall2_2
Route121_Cale_CheckMatchCall2_1:
	msgbox Route121_Text_CalePostBattle, MSGBOX_DEFAULT
	release
	end

Route121_Cale_CheckMatchCall2_2:
	goto Route121_Cale_RegisterMatchCall
	goto Route121_Cale_CheckMatchCall2_1


Route121_Cale_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALE
	release
	end


Route121_Cale_Rematch::
	trainerbattle_rematch TRAINER_CALE, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


CrystalCaveBrock_Text_0:
	.string "… … … … … … … …\n… … … … … … … …\pOh, so you're {PLAYER}? My apologies.\nI mistook you for someone else.\pI'm BROCK, LEADER of the PEWTER CITY\nPOKéMON GYM.\pI am looking for the legendary\nCRYSTAL ONIX in here.\pYou can join me, but if it comes\ndown to it, I will battle you for it.\pWhat do you say, {PLAYER}?$"

CrystalCaveBrock_Text_1:
	.string "No sweat, then!\nI am heading deeper into the cave\lin case you change your mind.$"

CrystalCaveBrock_Text_2:
	.string "Alright, then!\nIt should be far deeper into the cave.\pKeep up if you can!$"
