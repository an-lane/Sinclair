using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        ScriptManager.ScriptResourceMapping.AddDefinition("jquery", new ScriptResourceDefinition
        {
            Path = "~/Content/Js/jquery.min.js",
        });

    }
    //btnSubmitForm click
    protected void btnSubmitForm_Click(object sender, EventArgs e)
    {
        if (Page.IsValid)
        {
            //name
            string name = YourNameTextBox.Text;
            //email
            string email = YourEmailTextBox.Text;
            //phone
            string phone = YourPhoneTextBox.Text;
            //visible 
            MessageLabel.Visible = true;
            const string Format = "The Information Entered:<br />Name: {0}<br />Email: {1}<br />Phone: {2}";
            MessageLabel.Text = string.Format(Format, arg0: name, arg1: email, arg2: phone);
        }
    }
    //btnClearForm click
    protected void btnClearForm_Click(object sender, EventArgs e)
    {
        YourNameTextBox.Text = "";
        YourEmailTextBox.Text = "";
        YourPhoneTextBox.Text = "";
        MessageLabel.Visible = false;
    }
}