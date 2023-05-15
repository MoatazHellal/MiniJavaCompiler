import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EndbarComponent } from './endbar.component';

describe('EndbarComponent', () => {
  let component: EndbarComponent;
  let fixture: ComponentFixture<EndbarComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EndbarComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(EndbarComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
