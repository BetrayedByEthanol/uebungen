var votes = [{ id: 222, name: 'dass' }, { id: 22, name: 'dass' }, { id: 21, name: 'dass' }, { id: 121, name: 'dass' }];

if (votes.filter(e => { return e.id == 22222; }).length > 0) {
    console.log('yes')
} else {
    console.log('no');
}