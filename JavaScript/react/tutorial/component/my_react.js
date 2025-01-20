// 'use strict';

const root = ReactDOM.createRoot( document.getElementById( 'root' ) );
const element = <h1>Hello, world!</h1>;
root.render( element );

class ShoppingList extends React.Component {
  render() {
    // JSXの書き方
    return (
      <div className="shopping-list">
        <h1>Shopping List for {this.props.name}</h1>
        <ul>
          <li>Instagram</li>
          <li>WhatsApp</li>
          <li>Oculus</li>
        </ul>
      </div>
    );


    // JavaScriptでの書き方（上記JSXは以下のように変換される）
    // return React.createElement(
    //   'div',
    //   { className: 'shopping-list' },
    //   React.createElement(
    //     'h1',
    //     null,
    //     'Shopping List for {this.props.name}',
    //   ),
    //   React.createElement(
    //     'ul',
    //     null,
    //     React.createElement(
    //       'li',
    //       null,
    //       'Instagram'
    //     ),
    //     React.createElement(
    //       'li',
    //       null,
    //       'WhatsApp'
    //     ),
    //     React.createElement(
    //       'li',
    //       null,
    //       'Oculus'
    //     )
    //   )
    // );
  }
}

// Example usage: <ShoppingList name="Mark" />