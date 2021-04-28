using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    { }
    protected void btnCalculation_Click(object sender, EventArgs e){
        double calculatedInterest;
        string loanamount = "";
        double interestrate = 7;
        string timeperiod = "20";
        loanamount = txtLoanAmount.Text;
        interestrate = Convert.ToDouble(rlInterestRate.Text);
        timeperiod = ddlYears.SelectedItem.ToString();
        calculatedInterest = (Convert.ToDouble(txtLoanAmount.Text) * Convert.ToDouble(rlInterestRate.Text) * 
            Convert.ToDouble(ddlYears.SelectedItem.ToString()))/ 100;
        lblOutput.Visible = true;
        lblOutput.Text = "Total interest for a loan of $" + txtLoanAmount.Text + " at " + rlInterestRate.Text + "% interest for " +
            ddlYears.SelectedItem + " years is $" + calculatedInterest.ToString();
    }

    protected void btnReset_Click(object sender, EventArgs e)
    {
        lblOutput.Text = "";
        txtLoanAmount.Text = "";
        rlInterestRate.SelectedIndex = 2;
        ddlYears.SelectedIndex = 2;
    }
    
}