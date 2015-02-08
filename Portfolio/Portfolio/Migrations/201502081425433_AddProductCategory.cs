namespace Portfolio.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddProductCategory : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.ProductCategories",
                c => new
                    {
                        ProductCategoryId = c.Int(nullable: false, identity: true),
                        Name = c.String(),
                    })
                .PrimaryKey(t => t.ProductCategoryId);
            
            AddColumn("dbo.Products", "ProductCategoryID", c => c.Int(nullable: false));
            CreateIndex("dbo.Products", "ProductCategoryID");
            AddForeignKey("dbo.Products", "ProductCategoryID", "dbo.ProductCategories", "ProductCategoryId", cascadeDelete: true);
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Products", "ProductCategoryID", "dbo.ProductCategories");
            DropIndex("dbo.Products", new[] { "ProductCategoryID" });
            DropColumn("dbo.Products", "ProductCategoryID");
            DropTable("dbo.ProductCategories");
        }
    }
}
