namespace Portfolio.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class RemoveItemAndList : DbMigration
    {
        public override void Up()
        {
            DropForeignKey("dbo.Items", "ListID", "dbo.Lists");
            DropIndex("dbo.Items", new[] { "ListID" });
            DropTable("dbo.Items");
            DropTable("dbo.Lists");
        }
        
        public override void Down()
        {
            CreateTable(
                "dbo.Lists",
                c => new
                    {
                        ListID = c.Int(nullable: false, identity: true),
                        ListName = c.String(),
                    })
                .PrimaryKey(t => t.ListID);
            
            CreateTable(
                "dbo.Items",
                c => new
                    {
                        ItemID = c.Int(nullable: false, identity: true),
                        Description = c.String(),
                        ListID = c.Int(nullable: false),
                    })
                .PrimaryKey(t => t.ItemID);
            
            CreateIndex("dbo.Items", "ListID");
            AddForeignKey("dbo.Items", "ListID", "dbo.Lists", "ListID", cascadeDelete: true);
        }
    }
}
