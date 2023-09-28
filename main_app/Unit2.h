//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *QuestionLabel;
	TRadioButton *Answer1RadioButton;
	TRadioButton *Answer2RadioButton;
	TRadioButton *Answer3RadioButton;
	TButton *ConfirmButton;
	TLabel *Label2;
	TLabel *PointsLabel;
	TLabel *Label1;
	void __fastcall Answer1RadioButtonChange(TObject *Sender);
	void __fastcall Answer2RadioButtonChange(TObject *Sender);
	void __fastcall Answer3RadioButtonChange(TObject *Sender);
	void __fastcall ConfirmButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
