class FriendList
  include Enumerable

  def initialize( *friends )
    @friends = friends
  end

  def each
    for v in @friends
      yield v
    end
  end
end

friend_list = FriendList.new( 'Alice', 'Bob', 'Charlie' )

friend_list.count
friend_list.map{ |v| p v.upcase }
friend_list.find{ |v| puts v if( /b/ === v ) }