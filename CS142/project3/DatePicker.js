//onclick绑定的函数在事件触发时才调用,一定注意会不会产生覆盖问题.

"use strict";

function DatePicker(divID, callback)
{
    // callback is called when date is selected.
    // callback takes two arguments: id, fixedDate.
    // fixedDate has fields month, day and year.
    this.divID = divID;
    this.callback = callback;
}

//(1) 先选择将要变换的标签
//(2) 先用一个大的框架替换,再逐层细化

DatePicker.prototype.render = function(date)
{
    var element = document.getElementById(this.divID);
    element.innerHTML = 
    `<span id="previous-${this.divID}"class = "button"> \< </span>
    <span id="header-${this.divID}"> </span>
    <span id="next-${this.divID}" class="button"> \></span>
    <table id="cal-${this.divID}"></table>
    `;

    var cal = document.getElementById(`cal-${this.divID}`);
    var previous = document.getElementById(`previous-${this.divID}`);
    var next = document.getElementById(`next-${this.divID}`);
    var header = document.getElementById(`header-${this.divID}`);
    header.innerHTML = new Intl.DateTimeFormat('en-US',{month:'long'}).format(date) + " " + date.getFullYear()+" ";
    cal.innerHTML = `
    <tr>
         <th>Sun</th>
         <th>Mon</th>
         <th>Tue</th>
         <th>Wed</th>
         <th>Thur</th>
         <th>Fri</th>
         <th>Sat</th>
    </tr>
    `;

    var getCal = () =>{
        var tr = document.createElement("tr");
        var firstDay = new Date(date.getTime());
        firstDay.setDate(1);   //计算这个月开始日期
        var lastDay = new Date(date.getTime());
        lastDay.setMonth(date.getMonth()+1);
        lastDay.setDate(0);//这个月结束日期
        var numWeeks= Math.ceil((firstDay.getDay() + lastDay.getDate())/7); //这个月星期数
        var cursorDate = new Date(firstDay.getTime()); //cursorDate用来遍历星期
        cursorDate.setDate(cursorDate.getDate() - cursorDate.getDay());//从星期天开始遍历
        var getWeek = ()=>{
            var tr = document.createElement("tr");
            for(var day=0; day<7;day++)
            {
                var td = document.createElement("td");
                td.innerHTML = `${cursorDate.getDate()}`;
                var isCurrMonth = (firstDay.getMonth() == cursorDate.getMonth());
                let d = cursorDate.getDate();
                let m = new Intl.DateTimeFormat('en-US',{month:'long'}).format(cursorDate);
                let y = cursorDate.getFullYear();
                td.className = isCurrMonth?"normal":"dim";
                td.onclick = isCurrMonth?
                ()=>{
                
                    this.callback(this.divID,
                        {
                            day:d,
                            month: m,
                            year: y,
                            
                        })
                }:()=>{};
                tr.appendChild(td);
                cursorDate.setDate(cursorDate.getDate()+1);
            }
            return tr;
        }
        //遍历数字,生成日期标签,每7个组装成一行,每numWeeks行组装成cal标签
        for(var week  = 0; week<numWeeks; week++)
        {
            var tr = getWeek();
            cal.appendChild(tr);
        }
        
   
    }
    var changeMonth = (increment)=>{
        date.setMonth(date.getMonth() + increment,1);
        cal.innerHTML = `
        <tr>
         <th>Sun</th>
         <th>Mon</th>
         <th>Tue</th>
         <th>Wed</th>
         <th>Thur</th>
         <th>Fri</th>
         <th>Sat</th>
    </tr>
        `;
        getCal();
    }
    getCal();

    previous.onclick = ()=>{
        changeMonth(-1);
        header.innerHTML = new Intl.DateTimeFormat('en-US',{month:'long'}).format(date) + " " + date.getFullYear()+" ";
    }
    next.onclick = ()=>{
        changeMonth(1);
        header.innerHTML = new Intl.DateTimeFormat('en-US',{month:'long'}).format(date) + " " + date.getFullYear()+" ";
    }

}
