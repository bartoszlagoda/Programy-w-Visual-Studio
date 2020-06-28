//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include"mmsystem.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int liczby [1000];
bool gra_rozpoczeta = false;
int ile=0;
int licznik=0;//zlicza ilosc klikniec w instrument od nowa w kazdej rundzie

void sekwencja()
{
    Application->ProcessMessages();
    Sleep(1000);

    Form1->flet->Picture->LoadFromFile("image/flet.bmp");
    Form1->akordeon->Picture->LoadFromFile("image/akordeon.bmp");
    Form1->gitara->Picture->LoadFromFile("image/gitara.bmp");
    Form1->skrzypce->Picture->LoadFromFile("image/skrzypce.bmp");
    Form1->saksofon->Picture->LoadFromFile("image/saksofon.bmp");

    Form1->flet->Enabled = false;
    Form1->akordeon->Enabled = false;
    Form1->gitara->Enabled = false;
    Form1->skrzypce->Enabled = false;
    Form1->saksofon->Enabled = false;

    Form1->Label1->Caption = "Nastepny instrument za: 2";
    Application->ProcessMessages();//pomimo zamrozenia metoda sleep program bedzie reagowal
    Sleep(1000);
    Form1->Label1->Caption = "Rozpoznaj Instrument";
    Application->ProcessMessages();
    Sleep(1000);
    Form1->Label1->Caption = "Nastepny instrument za: 1";
    Application->ProcessMessages();
    Sleep(1000);

    Form1->Label1->Caption = "Ktory to instrument ?";
    Application->ProcessMessages();
    Sleep(1500);

    Form1->Label1->Caption = "Zapamietaj kolejnosc";
    Application->ProcessMessages();
    Sleep(1500);

    ile ++;//zwiekszam bo co runde jeden dz wiecej do odegrania
    for (int i=0; i<ile; i++)
    {
        switch(liczby[i])
        {
                case 1://gdy w tablicy mamy 1 to ma sie wykonac case 1
                {
                sndPlaySound("sound/flet.wav", SND_ASYNC);
                Form1->fletc->Visible = true;
                }
                        break;
                case 2:
                {
                sndPlaySound("sound/akordeon.wav", SND_ASYNC);
                Form1->akordeonc->Visible = true;
                }
                        break;
                case 3:
                {
                sndPlaySound("sound/gitara.wav", SND_ASYNC);
                Form1->gitarac->Visible = true;
                }
                        break;
                case 4:
                {
                sndPlaySound("sound/skrzypce.wav", SND_ASYNC);
                Form1->skrzypcec->Visible = true;
                }
                        break;
                case 5:
                {
                sndPlaySound("sound/saksofon.wav", SND_ASYNC);
                Form1->saksofonc->Visible = true;
                }
                        break;

        }
        Application->ProcessMessages();
        Sleep(1500);
        Form1->fletc->Visible = false;//chowam cien
        Form1->akordeonc->Visible = false;
        Form1->gitarac->Visible = false;
        Form1->skrzypcec->Visible = false;
        Form1->saksofonc->Visible = false;
        Application->ProcessMessages();
        Sleep(120);


    }
    Form1->flet->Enabled = true;//wlaczam dostepnosc klikniecia obrazka
    Form1->akordeon->Enabled = true;
    Form1->gitara->Enabled = true;
    Form1->skrzypce->Enabled = true;
    Form1->saksofon->Enabled = true;
    Form1->Label1->Caption = "Powtorz schemat";
    licznik=0;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{  
   randomize();//inicjowanie generatora liczb losowych
   for(int i=0; i<1000; i++)
   {
   liczby[i] = random(5) + 1;// random zastÍpuje rand ze strukturalnego c++ tablica 1000 liczb z zakresu od 1 do 5
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
  if(gra_rozpoczeta == false)
  {
        gra_rozpoczeta = true;
        sndPlaySound("sound/start.wav",SND_ASYNC);
        sekwencja();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::fletClick(TObject *Sender)
{
  if(gra_rozpoczeta == true)
  {
        licznik ++;//dzieki licznikowi wiem ktore to jest klikniecie
        if(liczby[licznik-1]!=1)//warunek pomylki dla fletu
        {
                ile--;//ile dobrze kliknalem
                Label1->Caption ="Blad!!! Twoj wynik: "+IntToStr(ile);
                sndPlaySound("sound/koniec.wav", SND_ASYNC);
                gra_rozpoczeta = false;
        }
        if(licznik == ile)
        {
        Label1->Caption = "Swietenie!!!";
        sekwencja();
        }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::akordeonClick(TObject *Sender)
{
 if(gra_rozpoczeta == true)
  {
        licznik ++;
        if(liczby[licznik-1]!=2)
        {
                ile--;//
                Label1->Caption ="Blad!!! Twoj wynik: "+IntToStr(ile);
                sndPlaySound("sound/koniec.wav", SND_ASYNC);
                gra_rozpoczeta = false;
        }
        if(licznik == ile)
        {
        Label1->Caption = "Swietnie!!!";
        sekwencja();
        }
  }
  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gitaraClick(TObject *Sender)
{
if(gra_rozpoczeta == true)
  {
        licznik ++;
        if(liczby[licznik-1]!=3)
        {
                ile--;
                Label1->Caption ="Blad!!! Twoj wynik: "+IntToStr(ile);
                sndPlaySound("sound/koniec.wav", SND_ASYNC);
                gra_rozpoczeta = false;
        }
        if(licznik == ile)
        {
        Label1->Caption = "Swietnie!!!";
        sekwencja();
        }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::skrzypceClick(TObject *Sender)
{
if(gra_rozpoczeta == true)
  {
        licznik ++;
        if(liczby[licznik-1]!=4)
        {
                ile--;
                Label1->Caption ="Blad!!! Twoj wynik: "+IntToStr(ile);
                sndPlaySound("sound/koniec.wav", SND_ASYNC);
                gra_rozpoczeta = false;
        }
        if(licznik == ile)
        {
        Label1->Caption = "Swietnie!!!";
        sekwencja();
        }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::saksofonClick(TObject *Sender)
{
if(gra_rozpoczeta == true)
  {
        licznik ++;
        if(liczby[licznik-1]!=5)
        {
                ile--;
                Label1->Caption ="Blad!!! Twoj wynik: "+IntToStr(ile);
                sndPlaySound("sound/koniec.wav", SND_ASYNC);
                gra_rozpoczeta = false;
        }
        if(licznik == ile)
        {
        Label1->Caption = "Doskonale!!!";
        sekwencja();
        }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::fletMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  flet->Picture->LoadFromFile("image/fletc.bmp");
  sndPlaySound("sound/flet.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::akordeonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  akordeon->Picture->LoadFromFile("image/akordeonc.bmp");
  sndPlaySound("sound/akordeon.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gitaraMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  gitara->Picture->LoadFromFile("image/gitarac.bmp");
  sndPlaySound("sound/gitara.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::skrzypceMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  skrzypce->Picture->LoadFromFile("image/skrzypcec.bmp");
  sndPlaySound("sound/skrzypce.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::saksofonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  saksofon->Picture->LoadFromFile("image/saksofonc.bmp");
  sndPlaySound("sound/saksofon.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::gitaraMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  gitara->Picture->LoadFromFile("image/gitara.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::fletMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  flet->Picture->LoadFromFile("image/flet.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::akordeonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  akordeon->Picture->LoadFromFile("image/akordeon.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::skrzypceMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  skrzypce->Picture->LoadFromFile("image/skrzypce.bmp");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::saksofonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  saksofon->Picture->LoadFromFile("image/saksofon.bmp");
}
//---------------------------------------------------------------------------



