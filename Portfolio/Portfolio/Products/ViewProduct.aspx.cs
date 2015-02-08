using Portfolio.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Portfolio.Products
{
    public partial class ViewProduct : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!string.IsNullOrEmpty(Request.QueryString["id"]))
            {
                var productID = int.Parse(Request.QueryString["id"]);
                using(var context = new PortfolioContext())
                {
                    var currentProduct = context.Products.Include("ProductCategory").Where(x => x.ProductID == productID).Single();
                    lblProductName.Text = currentProduct.Name;
                    lblPrice.Text = currentProduct.Price.ToString("c");
                    lblDescription.Text = currentProduct.Description;
                    lblCategory.Text = currentProduct.ProductCategory.Name;
                    lnkBack.NavigateUrl = lnkBack.NavigateUrl + currentProduct.ProductCategoryID;
                    lnkBack.Text = lnkBack.Text + " " + currentProduct.ProductCategory.Name;
                }
            }
        }
    }
}