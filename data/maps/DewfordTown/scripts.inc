DewfordTown_MapScripts::
	.byte 0


MandarinNorthGirl1::
	lock
	faceplayer
	msgbox MandarinNorthGirl1_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MandarinNorthGirl2::
	lock
	faceplayer
	msgbox MandarinNorthGirl2_Text_0, MSGBOX_AUTOCLOSE
	applymovement 4, MandarinGirl2_Move1
	waitmovement 0
	release
	end


MandarinGirl2_Move1:
	face_down
	step_end

MandarinWarehouseSign::
	lock
	msgbox MandarinWarehouseSign_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MandarinIslandNorthSign::
	lock
	msgbox MandarinIslandNorthSign_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MandarinNorthGirl1_Text_0:
	.string "I'm not sure why this place is called\nMANDARIN ISLAND NORTH.\pMANDARIN ISLAND SOUTH is quite far\nfrom here.$"

MandarinNorthGirl2_Text_0:
	.string "The ocean is so mesmerizing.\nI could gaze into it for eternity.$"

MandarinWarehouseSign_Text_0:
	.string "SILPH CO. WAREHOUSE\n“Trespassers will be punished!”$"

MandarinIslandNorthSign_Text_0:
	.string "MANDARIN ISLAND NORTH\nLoosen Up and Discover Inner Peace$"
