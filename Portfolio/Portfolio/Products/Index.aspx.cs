using Portfolio.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Portfolio.Products
{
    public partial class Index : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            using (var context = new PortfolioContext())
            {
                var productQuery = context.Products.AsQueryable();
                if(!string.IsNullOrEmpty(Request.QueryString["categoryID"]))
                {
                    var categoryID = int.Parse(Request.QueryString["categoryID"]);
                    productQuery = productQuery.Where(x => x.ProductCategoryID == categoryID);
                    lblPageTitle.Text = context.ProductCategories.Where(x => x.ProductCategoryId == categoryID).Single().Name;
                }
                grvProduct.DataSource = productQuery.OrderBy(product => product.Name).ToList();
                grvProduct.DataBind();
            }
        }
    }
}