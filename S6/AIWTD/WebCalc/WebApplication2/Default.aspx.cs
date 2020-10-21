using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication2
{
    public partial class Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Label3.Text = (string)Session["wynik"];
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            if(DropDownList1.Text=="1")
            {
                int wynik = Int32.Parse(TextBox1.Text) + Int32.Parse(TextBox2.Text);
                Label1.Text = wynik.ToString();
            }
            if (DropDownList1.Text == "2")
            {
                int wynik = Int32.Parse(TextBox1.Text) - Int32.Parse(TextBox2.Text);
                Label1.Text = wynik.ToString();
            }
            if (DropDownList1.Text == "3")
            {
                int wynik = Int32.Parse(TextBox1.Text) * Int32.Parse(TextBox2.Text);
                Label1.Text = wynik.ToString();
            }
            if (DropDownList1.Text == "4" && Int32.Parse(TextBox2.Text)!=0)
            {
                int wynik = Int32.Parse(TextBox1.Text) / Int32.Parse(TextBox2.Text);
                Label1.Text = wynik.ToString();
            }
            if (DropDownList1.Text == "4" && Int32.Parse(TextBox2.Text) == 0)
            {
                Label1.Text = "Nie dziel przez 0";
            }
            Session["wynik"] = Label1.Text;
            Label3.Text = (string)Session["wynik"];
        }
    }
}