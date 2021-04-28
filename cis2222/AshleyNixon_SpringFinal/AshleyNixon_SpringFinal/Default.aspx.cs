using System;
using System.Data;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Configuration;

public partial class _Default : System.Web.UI.Page {

    private string connectionString = WebConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;

    protected void Page_Load(object sender, EventArgs e)
    {
       
    }
   
    protected void btnSubmit_Click (object sender, EventArgs e)
    {
   
        SqlConnection con = new SqlConnection(connectionString);
        try
        {
            con.Open();
            SqlCommand cmd = new SqlCommand("INSERT INTO Client values(@FirstName,@LastName,@BusinessName,@Email,@Phone)", con);
            cmd.Parameters.AddWithValue("FirstName", FirstName.Text);
            cmd.Parameters.AddWithValue("LastName", LastName.Text);
            cmd.Parameters.AddWithValue("BusinessName", BusinessName.Text);
            cmd.Parameters.AddWithValue("Email", Email.Text);
            cmd.Parameters.AddWithValue("Phone", Phone.Text);
            cmd.ExecuteNonQuery();

            lblStatus.Text = "Submitted";

            FirstName.Text = "";
            LastName.Text = "";
            BusinessName.Text = "";
            Email.Text = "";
            Phone.Text = "";
        }
        catch(Exception err)
        {
            lblStatus.Text = "Error in submission:";
            lblStatus.Text += err.Message;
        }
        finally
        {
            con.Close();
        }


    }
 
}