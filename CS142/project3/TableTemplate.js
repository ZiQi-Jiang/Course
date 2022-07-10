// import {Cs142TemplateProcessor} from "./cs142-template-processor.js";
class TableTemplate{
    static fillIn(id,dict,columnName,) {
        let table = document.getElementById(id); // get the table
        table.style = `visibility: visible`;
        let tbody = table.firstElementChild;
        let th  = tbody.firstElementChild; 
        let template = new Cs142TemplateProcessor(th.innerHTML);
        th.innerHTML = template.fillIn(dict);
        let rows = tbody.childElementCount;
        let index = -1;
        let columns = th.childElementCount;
        for(let i = 0;i<columns;i++)
          if(columnName === th.children[i].innerHTML) index  = i;
        if(index===-1 && columnName !== undefined) return ;
        if(columnName === undefined)
        {

            for(index=0;index<columns;index++)
            for(let i=1;i<rows;i++)
            {
                let td = tbody.children[i].children[index];
                template = new Cs142TemplateProcessor(td.innerHTML);
                td.innerHTML = template.fillIn(dict);
            }
        }
        else
        {
            for(let i=1;i<rows;i++)
            {
                let td = tbody.children[i].children[index];
                template = new Cs142TemplateProcessor(td.innerHTML);
                td.innerHTML = template.fillIn(dict);
            }
        }
            

    }
}

