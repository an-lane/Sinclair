using System;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page {
    
    protected void Page_Load(object sender, EventArgs e) {
       
    }
    protected void CustomValidator1_ServerValidate(object source, ServerValidateEventArgs args)
    {
        int flag;
        if(Int32.TryParse(txtQty.Text,out flag))
        {
            args.IsValid = true;
        } else
        {
            args.IsValid = false;
        }
    }

}
