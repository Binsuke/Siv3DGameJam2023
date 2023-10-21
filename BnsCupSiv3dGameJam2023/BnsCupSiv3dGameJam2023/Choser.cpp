
#include "stdafx.h"

#include "Choser.h"


void Choser::NestOpenButton() {
	
	Circle circle{ Choser::Param::NestOpenButtonX + Choser::Param::nobSize / 2,Choser::NestOpenButtonY + Choser::Param::nobSize / 2, Choser::Param::nobSize };

	circle.draw(ColorF(0.3, 0.7, 1.0));
	circle.drawFrame(2, ColorF(0.1));
}


void Choser::GetFoodButton() {
	Circle circle{ Choser::Param::gfbX + Choser::Param::gfbSize / 2 ,Choser::Param::gfbY + Choser::Param::gfbSize / 2 ,Choser::Param::gfbSize };

	circle.draw(ColorF(0.5, 0.7, 1.0));
	circle.drawFrame(2,ColorF(0.1));
}


void Choser::GetWaterButton() {
	Circle circle{ Choser::Param::gwbX + Choser::Param::gwbSize / 2 , Choser::Param::gfbY + Choser::Param::gwbSize / 2 ,Choser::Param::gwbSize };

	circle.draw(ColorF(0.7, 0.7, 1.0));
	circle.drawFrame(2, ColorF(0.1));
}


void Choser::BuildButton() {
	Circle circle{ Choser::Param::bbX + Choser::Param::bbSize / 2 , Choser::Param::bbY + Choser::Param::bbSize / 2 , Choser::Param::bbSize };

	circle.draw(ColorF(0.7, 0.5, 0.2));
	circle.drawFrame(2, ColorF(0.1));

}

void Choser::ArmyTraning() {
	Circle circle{ Choser::Param::atX + Choser::Param::atSize / 2 ,Choser::Param::atY + Choser::Param::atSize / 2,Choser::Param::atSize };

	circle.draw(ColorF(1.0, 0.1, 0.1));
	circle.drawFrame(2, ColorF(0.1));

}


