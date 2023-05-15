import { Component, OnInit } from '@angular/core';
import { CompilerService } from '../compiler.service';

@Component({
  selector: 'app-content',
  templateUrl: './content.component.html',
  styleUrls: ['./content.component.css']
})
export class ContentComponent implements OnInit {

  constructor(private compilerService : CompilerService) { }
  inputCode:string="";
  outputMessage:string="";
compile():void{
  this.compilerService.compile(this.inputCode).subscribe((response:string) => { this.outputMessage=response })
}
  ngOnInit(): void {
  }

}
